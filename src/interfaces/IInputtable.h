#pragma once
#include "Actor.h"

class IInputtable {
    public:
        static const ushort ID = 4;

        virtual bool IsOfType(ushort id);

        virtual void ButtonPressed();
        virtual void ButtonReleased();
};