#pragma once
#include "../Actor.h"

class Sprite : public Actor {
    public:
        static const ushort ID = 1;

        int x;
        int y;
        int image;

        using Actor::Actor;

        virtual bool IsOfType(ushort id);

        virtual void Draw();
};