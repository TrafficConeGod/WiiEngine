#pragma once
#include "Inputtable.h"

class BouncingBallGenerator : public Inputtable {
    public:
        static const short ID = 4;

        using Inputtable::Inputtable;
        virtual void ButtonPressed(uint buttonType);
};