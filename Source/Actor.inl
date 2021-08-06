#include "Actor.h"

template<typename T>
void Actor::UseOf(void (*func)(T*)) {
    if (initialized && alive && IsOfType(T::ID)) {
        func(dynamic_cast<T*>(this));
    }
}