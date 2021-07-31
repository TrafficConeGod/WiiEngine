#include "Character.h"
#include "templates.h"

bool Character::IsOfType(ushort id) {
    return id == ID || ISprite::IsOfType(id) || IInputtable::IsOfType(id) || Actor::IsOfType(id);
}

void Character::Create() {
    Actor::Create();
    pos = Vector2i(10000, 10000);
	image = 0;
}

void Character::ButtonPressed() {
    IInputtable::ButtonPressed();
    pos = Vector2i(30000, 30000);
}