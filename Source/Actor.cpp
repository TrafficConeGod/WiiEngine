#include "Actor.h"
#include "Stage.h"
#include "Wii/mem.h"
#include "Wii/io.h"

Actor::Actor(Stage* _stage) : stage{_stage} {}

bool Actor::IsOfType(ushort id) {
    return id == ID;
}

void Actor::Load(DataStream& stream) {}

void Actor::Create() {}

void Actor::Destroy() {}

void Actor::Update() {}