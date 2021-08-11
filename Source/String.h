#pragma once
#include "DataStream.h"

class String {
    private:
        char* buf;
    public:
        size_t size;

        String();

        void operator=(const String& str);
        String(const String& str);

        void operator=(const char* constPtr);
        String(const char* constPtr);

        void Load(DataStream& stream);
        String(DataStream& stream);

        ~String();

        operator char*();
        operator const char*();
};