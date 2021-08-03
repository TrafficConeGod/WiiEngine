#pragma once
#include "DataStream.h"
#include "Array.h"

class Actor;

class Stage {
    private:
        Array<Actor*> actors;
    public:
        ~Stage();

        Actor* AllocateActor(ushort id);

        Actor* LoadActor(DataStream& stream);
        void LoadActors(DataStream& stream);

        void DoAction(void (*action)(Actor*));
        template<typename T>
        void DoActionOn(void (*action)(T*));
};