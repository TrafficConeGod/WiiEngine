#include "DataStream.h"

DataStream::DataStream(void* _buf, size_t _size) : buf{_buf}, size{_size} {}

bool DataStream::IsReadable() {
    return pos < size;
}