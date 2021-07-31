#pragma once
#include "Sprite.h"
#include "Inputtable.h"

class Character : public Inputtable {
    private:
        Sprite* sprite;
    public:
        static const ushort ID = 3;

        Character(World* world);
        virtual bool IsOfType(ushort id);

        virtual void Create();
        virtual void ButtonPressed();
};