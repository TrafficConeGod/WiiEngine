#include "String.h"
#include <stdlib.h>
#include "Array.h"

String::String() {
    size = 0;
    buf = (char*)malloc(1);
    buf[0] = '\0';
}

void String::operator=(const String& str) {
    size = str.size;
    buf = (char*)malloc(str.size + 1);
    for (size_t i = 0; i < size; i++) {
        buf[i] = str.buf[i];
    }
}

String::String(const String& str) {
    *this = str;
}

void String::operator=(const char* constPtr) {
    size = strlen(constPtr);
    buf = (char*)malloc(size + 1);
    for (size_t i = 0; i < size; i++) {
        buf[i] = constPtr[i];
    }
}

String::String(const char* constPtr) {
    *this = constPtr;
}

void String::Load(DataStream& stream) {
    Array<char> charArray;
    for (size_t i = 0; stream.IsReadable(); i++) {
        char ch;
        stream >> ch;
        charArray << ch;
        if (ch == 0) {
            break;
        }
    }
    size = charArray.size;
    buf = (char*)malloc(size + 1);
    for (size_t i = 0; i < size; i++) {
        buf[i] = charArray[i];
    }
}

String::String(DataStream& stream) {
    Load(stream);
}

String::~String() {
    free(buf);
}