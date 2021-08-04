#pragma once
#include "Sprite.h"
#include "Inputtable.h"

class Character : public virtual Sprite, public virtual Inputtable {
    public:
        static const ushort ID = 4;

        Character(Stage* stage);
        virtual bool IsOfType(ushort id);

        virtual void Create();
        virtual void ButtonPressed();
};