#include "file.h"
#include "io.h"

bool (*actionFunc)(void*, size_t);
bool Action(void* buf, size_t size, void*) {
	return actionFunc(buf, size);
}

bool UseFile(const char* path, bool (*func)(void*, size_t)) {
	actionFunc = func;
    return UseFileWith<void*>(path, nullptr, Action);
}