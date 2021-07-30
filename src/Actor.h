#pragma once
#include "wii/type.h"
#include "World.h"
#include "DataStream.h"

class Actor {
    protected:
        World* world;
    public:
        ushort id;

        Actor(World& world);

        virtual void Load(DataStream& stream);
        virtual void Save(DataStream& stream);

        virtual void Create();
        virtual void Destroy();
        virtual void Update();
};