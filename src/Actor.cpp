#include "Actor.h"
#include "wii/mem.h"
#include "wii/io.h"

Actor::Actor(World* _world) : world{_world} {}

bool Actor::IsOfType(ushort id) {
    return id == ID;
}

void Actor::Load(DataStream& stream) {
    
}

void Actor::Save(DataStream& stream) {
    
}

void Actor::Create() {
}

void Actor::Destroy() {
}

void Actor::Update() {
}