#pragma once
#include "Wii/type.h"
#include "DataStream.h"
#include "Array.h"

class Stage;

class Actor {
    protected:
        bool initialized = false;
        bool alive = false;

        Stage* stage;
        Array<Actor*> children;

        Actor* CreateChild(ushort id);
        Actor* CreateChildFrom(DataStream& stream);

        virtual void Create();
    public:
        static const uint ID = 1;

        Actor(Stage* stage);

        virtual bool IsOfType(ushort id);

        void Use(void (*func)(Actor*));

        template<typename T>
        void UseOf(void (*func)(T*));

        void Initialize();

        virtual void Load(DataStream& stream);
        virtual void Destroy();
        virtual void Update();
};

#include "Actor.inl"