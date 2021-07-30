#pragma once
#include "../Actor.h"

class MyActor : public Actor {
    public:
        static const ushort ID = 0;

        int x;
        int y;

        using Actor::Actor;

        virtual void Create();
};