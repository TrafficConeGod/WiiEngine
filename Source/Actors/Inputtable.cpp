#include "Inputtable.h"

bool Inputtable::IsOfType(short id) {
    return id == ID || Actor::IsOfType(id);
}

void Inputtable::ButtonPressed(uint) {}

void Inputtable::ButtonReleased() {}