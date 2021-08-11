#pragma once
#include "Actor.h"
#include "Vector2.h"

class Sprite : public virtual Actor {
    public:
        static const short ID = 2;

        Vector2i pos;
        int image;

        using Actor::Actor;
        virtual bool IsOfType(short id);
        
        virtual void Load(DataStream& stream);

        virtual void Draw();
};