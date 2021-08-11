#pragma once
#include "Actor.h"

class Inputtable : public virtual Actor {
    public:
        static const short ID = 3;

        using Actor::Actor;
        virtual bool IsOfType(short id);

        virtual void ButtonPressed(uint buttonType);
        virtual void ButtonReleased();
};