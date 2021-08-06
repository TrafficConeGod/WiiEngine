#include "Actor.h"
#include "Stage.h"
#include "Wii/mem.h"
#include "Wii/io.h"

void Actor::Use(void (*func)(Actor*)) {
    if (alive) {
        func(this);
    }
}

void Actor::Initialize() {
    if (!initialized) {
        initialized = true;
        Create();
    }
}

Actor* Actor::CreateChild(ushort id) {
    Actor* actor = stage->AllocateActor(id);
    actor->Create();
    children.Push(actor);
}

Actor::Actor(Stage* _stage) : stage{_stage} {}

bool Actor::IsOfType(ushort id) {
    return id == ID;
}

void Actor::Load(DataStream& stream) {}

void Actor::Create() {
    alive = true;
}

void Actor::Destroy() {
    alive = false;
    for (size_t i = 0; i < children.size; i++) {
        Actor* child = children[i];
        child->Destroy();
    }
}

void Actor::Update() {}