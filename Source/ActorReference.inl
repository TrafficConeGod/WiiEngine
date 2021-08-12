#include "ActorReference.h"

template<typename A>
ActorReference<A>::ActorReference() {}

template<typename A>
void ActorReference<A>::operator=(Actor* actor) {
    stage = actor->stage;
    index = actor->index;
}

template<typename A>
ActorReference<A>::ActorReference(Actor* actor) {
    *this = actor;
}

template<typename A>
void ActorReference<A>::Load(Stage* stage, DataStream& stream) {
    this->stage = stage;
    stream >> index;
}

template<typename A>
bool ActorReference<A>::IsEmpty() {
    return ((A*)(*this)) == nullptr;
}

template<typename A>
ActorReference<A>::operator A*() {
    if (stage == nullptr) {
        return nullptr;
    }
    Actor* actor = stage->GetActorAtIndex(index);
    if (actor->IsOfType(A::ID)) {
        return dynamic_cast<A*>(actor);
    } else {
        return nullptr;
    }
}