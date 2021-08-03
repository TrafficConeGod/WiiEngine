#include "Character.h"
#include "templates.h"

Character::Character(World* _world) : Sprite(_world), Inputtable(_world), Actor(_world) {}

bool Character::IsOfType(ushort id) {
    return id == ID || Sprite::IsOfType(id) || Inputtable::IsOfType(id);
}

void Character::Create() {
    Inputtable::Create();
    pos = Vector2i(10000, 10000);
	image = 0;
}

void Character::ButtonPressed() {
    Inputtable::ButtonPressed();
    pos = Vector2i(30000, 30000);
}