#include "file.h"
#include "io.h"

template<typename T>
bool UseFileWith(const char* path, const T& val, bool (*func)(void*, size_t, T)) {
    if (access(path, F_OK) != 0) {
		Print("File not found");
		return false;
	}

	FILE* file = fopen(path, "rb");

	FileStat fileStat;
	stat(path, &fileStat);

	size_t size = fileStat.st_size;
	char buf[size];
	fread(buf, 1, size, file);
	fclose(file);
    if (!func(buf, size, val)) {
		Print("Error in using file");
		return false;
	}
	return true;
}