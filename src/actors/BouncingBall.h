#pragma once
#include "Sprite.h"

class BouncingBall : public Sprite {
    public:
        static const ushort ID = 2;

        int dx;
        int dy;

        using Sprite::Sprite;

        virtual bool IsOfType(ushort id);

        virtual void Create();
        virtual void Update();
};