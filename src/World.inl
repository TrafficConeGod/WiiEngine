#include "World.h"

template<typename T>
void World::DoActionOn(void (*action)(T*)) {
    for (size_t i = 0; i < actors.size; i++) {
        auto actor = actors[i];
        if (actor->IsOfType(T::ID)) {
            action(dynamic_cast<T*>(actor));
        }
    }
}