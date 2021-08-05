#include "DataStream.h"

template<typename T>
T* DataStream::PtrAtPos() {
    return (T*)(buf + pos);
}

template<typename T>
DataStream& DataStream::operator>>(T& val) {
    T* ptr = PtrAtPos<T>();
    val = *ptr;
    pos += sizeof(T);
    return *this;
}