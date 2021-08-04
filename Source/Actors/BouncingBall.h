#pragma once
#include "Sprite.h"
#include "Vector2.h"

class BouncingBall : public virtual Sprite {
    public:
        static const ushort ID = 5;

        Vector2i vel;

        using Sprite::Sprite;
        virtual bool IsOfType(ushort id);

        virtual void Load(DataStream& stream);
        virtual void Create();
        virtual void Update();
};