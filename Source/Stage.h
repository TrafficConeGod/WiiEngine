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
        bool LoadActors(DataStream& stream);
        bool LoadFromFile(const char* path);

        void Initialize();
        void Destroy();
        void UseActors(void (*action)(Actor*));
        template<typename T>
        void UseActorsOf(void (*action)(T*));
};

#include "Stage.inl"