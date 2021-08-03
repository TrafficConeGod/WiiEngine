#pragma once
#include "wii/type.h"
#include "World.h"
#include "DataStream.h"

class Actor {
    protected:
        World* world;
    public:
        static const uint ID = 0;

        explicit Actor(World* world);

        static bool CheckType(ushort id);
        virtual bool IsOfType(ushort id);

        virtual void Load(DataStream& stream);
        virtual void Save(DataStream& stream);

        virtual void Create();
        virtual void Destroy();
        virtual void Update();
};