#include "Character.h"
#include "../templates.h"

bool Character::IsOfType(ushort id) {
    return id == ID || Sprite::IsOfType(id);
}

void Character::Create() {
    Sprite::Create();
    pos = Vector2i(10000, 10000);
	image = 0;
}

void Character::ButtonPressed() {
    Sprite::ButtonPressed();
    pos = Vector2i(30000, 30000);
}