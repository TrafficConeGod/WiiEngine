#pragma once
#include "Sprite.h"
#include "Vector2.h"

class BouncingBall : public virtual Sprite {
    public:
        static const ushort ID = 2;

        Vector2i vel;

        using Sprite::Sprite;
        static bool CheckType(ushort id);
        virtual bool IsOfType(ushort id);

        virtual void Create();
        virtual void Update();
};