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
    puts("Default actor create");
}

void Actor::Destroy() {
    puts("Default actor destroy");
}

void Actor::Update() {
    puts("Default actor update");
}