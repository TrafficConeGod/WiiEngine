#pragma once
#include "Wii/io.h"

template<typename T>
class Array {
    public:
        T* buf = nullptr;
        size_t size = 0;

        ~Array();

        T& operator[](size_t index);
        T& SafeIndex(size_t index);

        void Push(const T& val);
        T Pop();
};