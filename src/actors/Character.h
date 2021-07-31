#pragma once
#include "interfaces/ISprite.h"
#include "interfaces/IInputtable.h"
#include "Actor.h"

class Character : public Actor, public virtual IInputtable, public virtual ISprite {
    public:
        static const ushort ID = 3;

        using Actor::Actor;
        virtual bool IsOfType(ushort id);

        virtual void Create();
        virtual void ButtonPressed();
};