#pragma once
#include "type.h"

void* Allocate(size_t size);
void Free(void* ptr);
size_t GetSize(void* ptr);