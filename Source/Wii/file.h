#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct stat FileStat;

template<typename T>
bool UseFileWith(const char* path, const T& val, bool (*func)(void*, size_t, T));

bool UseFile(const char* path, bool (*func)(void*, size_t));

#include "file.inl"