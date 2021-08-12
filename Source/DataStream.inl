#include "DataStream.h"
#include <stdlib.h>

template<typename T>
T* DataStream::PtrAtPos() {
    if (pos + sizeof(T) > size) {
        Error("Attempt to index out of DataStream bounds");
    }
    return (T*)((intptr_t)buf + pos);
}

template<typename T>
DataStream& DataStream::operator>>(T& val) {
    T* ptr = PtrAtPos<T>();
    val = *ptr;
    pos += sizeof(T);
    return *this;
}