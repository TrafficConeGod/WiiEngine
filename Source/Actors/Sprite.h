#pragma once
#include "Actor.h"
#include "Vector2.h"
#include "ActorReference.h"
#include "TextureResource.h"

class Sprite : public virtual Actor {
    public:
        static const short ID = 1;

        Vector2i pos;
        Vector2i size;
        ActorReference<TextureResource> textureRef;

        using Actor::Actor;
        virtual bool IsOfType(short id);
        
        virtual void Load(DataStream& stream);

        virtual void Draw();
};