#include "Actor.h"
#include "Stage.h"
#include "Wii/mem.h"
#include "Wii/io.h"

Actor::Actor(Stage* _stage) : stage{_stage}, index{_stage->GetCurrentIndex()} {}

static void DestroyAction(Actor* actor) {
    actor->Destroy();
}

Actor::~Actor() {
    Use(DestroyAction);
}

void Actor::Initialize() {
    if (!initialized) {
        initialized = true;
        Create();
    }
}

void Actor::Use(void (*func)(Actor*)) {
    if (initialized && alive) {
        func(this);
    }
}

Actor* Actor::CreateChild(short id) {
    Actor* actor = stage->AllocateActor(id);
    actor->Initialize();
    children << actor;
    return actor;
}

Actor* Actor::CreateChildFrom(DataStream& stream) {
    Actor* actor = stage->LoadActor(stream);
    actor->Initialize();
    children << actor;
    return actor;
}

void Actor::MakeChild(Actor* actor) {
    children << actor;
}

bool Actor::IsOfType(short id) {
    return id == ID;
}

void Actor::Load(DataStream& stream) {}

void Actor::Create() {
    alive = true;
}

void Actor::Destroy() {
    alive = false;
    stage->RemoveActor(index);
    for (size_t i = 0; i < children.size; i++) {
        Actor* child = children[i];
        child->Destroy();
    }
}

void Actor::Update() {}