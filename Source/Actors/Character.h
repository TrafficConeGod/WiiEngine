#pragma once
#include "Sprite.h"
#include "Inputtable.h"

class Character : public virtual Sprite, public virtual Inputtable {
    public:
        static const short ID = 2;

        Character(Stage* stage);
        virtual bool IsOfType(short id);

        virtual void Create();
        virtual void ButtonPressed(uint buttonType);
};