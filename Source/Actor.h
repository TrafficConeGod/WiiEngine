#pragma once
#include "Wii/type.h"
#include "Stage.h"
#include "DataStream.h"

class Actor {
    protected:
        Stage* stage;
    public:
        static const uint ID = 0;

        Actor(Stage* stage);

        virtual bool IsOfType(ushort id);

        virtual void Load(DataStream& stream);
        virtual void Save(DataStream& stream);

        virtual void Create();
        virtual void Destroy();
        virtual void Update();
};