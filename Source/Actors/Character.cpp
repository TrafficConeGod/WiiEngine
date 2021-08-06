#include "Character.h"

Character::Character(Stage* _stage) : Sprite(_stage), Inputtable(_stage), Actor(_stage) {}

bool Character::IsOfType(ushort id) {
    return id == ID || Sprite::IsOfType(id) || Inputtable::IsOfType(id);
}

void Character::Create() {
    Inputtable::Create();
    pos = Vector2i(10000, 10000);
	image = 0;
}

void Character::ButtonPressed(uint buttonType) {
    if (buttonType & WPAD_BUTTON_2) {
        Inputtable::ButtonPressed(buttonType);
        pos = Vector2i(30000, 30000);
    }
}