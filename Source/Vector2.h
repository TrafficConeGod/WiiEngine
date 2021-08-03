#pragma once
#include "Wii/type.h"

template<typename T>
class Vector2 {
    public:
        T x;
        T y;

        Vector2();
        Vector2(T x, T y);
};

typedef Vector2<int> Vector2i;
typedef Vector2<uint> Vector2u;
typedef Vector2<float> Vector2f;

#include "Vector2.inl"