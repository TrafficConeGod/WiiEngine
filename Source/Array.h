#pragma once
#include "Wii/io.h"

template<typename T>
class Array {
    public:
        T* buf = nullptr;
        size_t size = 0;

        ~Array();

        inline T& operator[](size_t index);
        T& SafeIndex(size_t index);

        inline void Push(const T& val);
        inline T Pop();
};

#include "Array.inl"