#pragma once
#include "Inputtable.h"
#include "../Vector2.h"

class Sprite : public Inputtable /** Coming from working on an ecs this feels so fucking wrong to me */ {
    public:
        static const ushort ID = 1;

        Vector2i pos;
        int image;

        using Inputtable::Inputtable;
        virtual bool IsOfType(ushort id);

        virtual void Draw();
};