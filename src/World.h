#pragma once
#include "DataStream.h"
#include "Array.h"

class Actor;

class World {
    private:
        Array<Actor*> actors;
    public:
        Actor* AllocateActor(ushort id);

        Actor* LoadActor(DataStream& stream);
        void LoadActors(DataStream& stream);

        void DoAction(void (*action)(Actor*));
        template<typename T>
        void DoActionOn(void (*action)(T*));
};