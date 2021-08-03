#pragma once
#include "Actor.h"

class Inputtable : public virtual Actor {
    public:
        static const ushort ID = 4;

        using Actor::Actor;
        static bool CheckType(ushort id);
        virtual bool IsOfType(ushort id);

        virtual void ButtonPressed();
        virtual void ButtonReleased();
};