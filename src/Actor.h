#pragma once
#include "Wii/type.h"
#include "World.h"
#include "DataStream.h"

class Actor {
    protected:
        World* world;
    public:
        static const uint ID = 0;

        Actor(World* world);

        virtual bool IsOfType(ushort id);

        virtual void Load(DataStream& stream);
        virtual void Save(DataStream& stream);

        virtual void Create();
        virtual void Destroy();
        virtual void Update();
};