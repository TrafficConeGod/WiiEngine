#pragma once
#include "Actor.h"

class Inputtable : public virtual Actor {
    public:
        static const ushort ID = 3;

        using Actor::Actor;
        virtual bool IsOfType(ushort id);

        virtual void ButtonPressed(uint buttonType);
        virtual void ButtonReleased();
};