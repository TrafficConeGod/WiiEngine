#pragma once
#include "DataStream.h"
#include "Array.h"

class Actor;

class Stage {
    private:
        Array<Actor*> actors;
    public:
        ~Stage();

        size_t GetCurrentIndex();

        Actor* AllocateActor(short id);
        void RemoveActor(size_t index);

        Actor* LoadActor(DataStream& stream);
        bool LoadActors(DataStream& stream);
        bool LoadFromFile(const char* path);

        void Initialize();
        void Destroy();

        void UseActors(void (*action)(Actor*));
        
        template<typename A>
        void UseActorsOf(void (*action)(A*));

        template<typename T>
        void UseActorsWith(const T& val, void (*func)(Actor*, T));

        template<typename A, typename T>
        void UseActorsOfWith(const T& val, void (*func)(A*, T));
};

#include "Stage.inl"