#pragma once
#include "Actor.h"

class Inputtable : public virtual Actor {
    public:
        static const ushort ID = 4;

        using Actor::Actor;
        virtual bool IsOfType(ushort id);

        virtual void ButtonPressed();
        virtual void ButtonReleased();
};