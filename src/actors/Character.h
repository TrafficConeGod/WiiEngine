#pragma once
#include "Sprite.h"

class Character : public Sprite {
    private:
        Sprite* sprite;
    public:
        static const ushort ID = 3;

        using Sprite::Sprite;
        virtual bool IsOfType(ushort id);

        virtual void Create();
        virtual void ButtonPressed();
};