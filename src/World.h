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
        void DoActionOn(ushort id, void (*action)(Actor*));
};