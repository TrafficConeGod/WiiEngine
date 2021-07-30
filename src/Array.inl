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
        puts("Out of bounds");
        exit(0);
    }
    return buf[index];
}

template<typename T>
void Array<T>::Push(const T& val) {
    size += 1;
    buf = (T*)realloc(buf, size * sizeof(T));
    buf[size - 1] = val;
}

template<typename T>
T Array<T>::Pop() {
    size -= 1;
    T val = buf[size];
    realloc(buf, size * sizeof(T));
    return val;
}