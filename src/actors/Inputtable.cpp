#include "Inputtable.h"

bool Inputtable::CheckType(ushort id) {
    return id == ID || Actor::CheckType(id);
}

bool Inputtable::IsOfType(ushort id) {
    return CheckType(id);
}

void Inputtable::ButtonPressed() {
	puts("Pressed");
}

void Inputtable::ButtonReleased() {
    
}