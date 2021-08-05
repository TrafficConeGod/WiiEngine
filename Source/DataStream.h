#pragma once
#include "Wii/type.h"
#include "Wii/io.h"

class DataStream {
    private:
        size_t pos = 0;

        template<typename T>
        T* PtrAtPos();
    public:
        void* buf;
        size_t size;

        DataStream(void* buf, size_t size);

        template<typename T>
        DataStream& operator>>(T& val);

        bool IsReadable();

        void ResetHead();
};

#include "DataStream.inl"