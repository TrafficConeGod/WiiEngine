#pragma once
#include "Wii/type.h"
#include "DataStream.h"
#include "Array.h"

class Stage;

class Actor {
    protected:
        size_t index;
        bool initialized = false;
        bool alive = false;

        Stage* stage;
        Array<Actor*> children;

        Actor* CreateChild(short id);
        Actor* CreateChildFrom(DataStream& stream);

        virtual void Create();
    public:
        static const uint ID = 0;

        Actor(Stage* stage);

        virtual bool IsOfType(short id);

        void Use(void (*func)(Actor*));

        template<typename A>
        void UseOf(void (*func)(A*));

        template<typename T>
        void UseWith(const T& val, void (*func)(Actor*, T));

        template<typename A, typename T>
        void UseOfWith(const T& val, void (*func)(A*, T));

        void Initialize();

        virtual void Load(DataStream& stream);
        virtual void Destroy();
        virtual void Update();
};

#include "Actor.inl"