#pragma once
#include "Wii/type.h"
#include "DataStream.h"

class Stage;

class Actor {
    protected:
        Stage* stage;
    public:
        static const uint ID = 1;

        Actor(Stage* stage);

        virtual bool IsOfType(ushort id);

        virtual void Load(DataStream& stream);

        virtual void Create();
        virtual void Destroy();
        virtual void Update();
};