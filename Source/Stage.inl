#include "Stage.h"
#include "Actor.h"

template<typename T>
void Stage::UseActorsOf(void (*func)(T*)) {
    for (size_t i = 0; i < actors.size; i++) {
        auto actor = actors[i];
        actor->UseOf(func);
    }
}