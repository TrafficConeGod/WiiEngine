#pragma once
#include "Sprite.h"
#include "Inputtable.h"

class Character : public virtual Inputtable, public virtual Sprite {
    public:
        static const ushort ID = 3;

        Character(Stage* stage);
        virtual bool IsOfType(ushort id);

        virtual void Create();
        virtual void ButtonPressed();
};