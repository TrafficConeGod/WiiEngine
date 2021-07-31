#pragma once
#include "Vector2.h"

class ISprite {
    public:
        static const ushort ID = 1;

        Vector2i pos;
        int image;

        virtual bool IsOfType(ushort id);

        virtual void Draw();
};