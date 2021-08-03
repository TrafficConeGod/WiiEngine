#pragma once
#include "Wii/type.h"
#include "Wii/io.h"

class DataStream {
    private:
        size_t pos = 0;

        template<typename T>
        inline T* PtrAtPos();
    public:
        void* buf;
        size_t size;

        DataStream(void* buf, size_t size);

        template<typename T>
        inline DataStream& operator<<(const T& val);

        template<typename T>
        inline DataStream& operator>>(T& val);

        inline bool IsReadable();
};

#include "DataStream.inl"