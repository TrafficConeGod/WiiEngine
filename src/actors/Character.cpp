#include "Character.h"
#include "../templates.h"

Character::Character(World* _world) : Inputtable(_world) {
    sprite = (Sprite*)world->AllocateActor(Sprite::ID);
}

bool Character::IsOfType(ushort id) {
    return id == ID || sprite->IsOfType(id) || Inputtable::IsOfType(id);
}

void Character::Create() {
    Actor::Create();
    if (!sprite->created) {
        sprite->Create();
    }
    sprite->image = 0;
    sprite->pos = Vector2i(300, 300);
}

void Character::ButtonPressed() {
    Inputtable::ButtonPressed();
    sprite->pos = Vector2i(100, 100);
}