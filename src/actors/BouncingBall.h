#pragma once
#include "Actor.h"
#include "interfaces/ISprite.h"
#include "Vector2.h"

class BouncingBall : public Actor, public virtual ISprite {
    public:
        static const ushort ID = 2;

        Vector2i vel;

        using Actor::Actor;
        virtual bool IsOfType(ushort id);

        virtual void Create();
        virtual void Update();
};