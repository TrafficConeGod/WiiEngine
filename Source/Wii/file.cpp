#include "file.h"
#include "io.h"

bool UseFile(const char* path, bool (*func)(void*, size_t)) {
    if (access(path, F_OK) != 0) {
		Print("File not found");
		return false;
	}

	FILE* file = fopen(path, "rb");

	FileStat fileStat;
	stat(path, &fileStat);

	size_t size = fileStat.st_size;
	char buf[size];
	fgets(buf, size, file);
    return func(buf, size);
}