#include "Wii/io.h"
#include "Array.h"

template<typename T>
Array<T>::~Array() {
    if (buf != nullptr) {
        free(buf);
    }
}

template<typename T>
T& Array<T>::operator[](size_t index) {
    return buf[index];
}

template<typename T>
T& Array<T>::SafeIndex(size_t index) {
    if (index >= size) {
        Error("Out of bounds");
        exit(0);
    }
    return buf[index];
}

template<typename T>
Array<T>& Array<T>::operator<<(const T& val) {
    size += 1;
    buf = (T*)realloc(buf, size * sizeof(T));
    buf[size - 1] = val;
    return *this;
}

template<typename T>
Array<T>& Array<T>::operator>>(T& val) {
    size -= 1;
    val = buf[size];
    realloc(buf, size * sizeof(T));
    return *this;
}