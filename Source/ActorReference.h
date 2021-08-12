#pragma once
#include "Stage.h"

template<typename A>
class ActorReference {
    private:
        Stage* stage = nullptr;
        size_t index = 0;
    public:
        ActorReference();

        void operator=(Actor* actor);
        ActorReference(Actor* actor);
        void Load(Stage* stage, DataStream& stream);
        
        bool IsEmpty();
        operator A*();
};

#include "ActorReference.inl"