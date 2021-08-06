#pragma once
#include "Inputtable.h"

class BouncingBallGenerator : public Inputtable {
    public:
        static const ushort ID = 6;

        using Inputtable::Inputtable;
        virtual void ButtonPressed();
};