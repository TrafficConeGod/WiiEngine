#pragma once
#include "../Actor.h"

class Sprite : public Actor {
    public:
        static const ushort ID = 1;

        int x;
        int y;
        int dx;
        int dy;
        int image;

        using Actor::Actor;

        virtual void Create();
        virtual void Update();
        virtual void Draw();
};