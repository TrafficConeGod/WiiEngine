#pragma once
#include "wii/type.h"
#include "wii/io.h"

class DataStream {
    private:
        uchar buf;
        size_t size;
    public:
        DataStream(size_t size);
        ~DataStream();

        template<typename T>
        DataStream& operator<<(const T& val);

        template<typename T>
        DataStream& operator>>(T& val);

        bool IsReadable();
};