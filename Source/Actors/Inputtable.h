#pragma once
#include "Actor.h"

class Inputtable : public virtual Actor {
    public:
        static const short ID = -1;

        using Actor::Actor;
        virtual bool IsOfType(short id);

        virtual void ButtonsDown(uint buttons);
        virtual void ButtonsHeld(uint buttons);
        virtual void ButtonsUp(uint buttons);
};