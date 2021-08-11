#include "Stage.h"
#include "Actor.h"

template<typename A>
void Stage::UseActorsOf(void (*func)(A*)) {
    for (size_t i = 0; i < actors.size; i++) {
        auto actor = actors[i];
        actor->UseOf(func);
    }
}

template<typename T>
void Stage::UseActorsWith(const T& val, void (*func)(Actor*, T)) {
    for (size_t i = 0; i < actors.size; i++) {
        auto actor = actors[i];
        actor->UseWith(val, func);
    }
}

template<typename A, typename T>
void Stage::UseActorsOfWith(const T& val, void (*func)(A*, T)) {
    for (size_t i = 0; i < actors.size; i++) {
        auto actor = actors[i];
        actor->UseOfWith(val, func);
    }
}