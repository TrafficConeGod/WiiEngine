#pragma once
#include "../Actor.h"
#include "../Vector2.h"

class Sprite : public Actor {
    public:
        static const ushort ID = 1;

        Vector2i pos;
        int image;

        using Actor::Actor;

        virtual bool IsOfType(ushort id);

        virtual void Draw();
};