#include "io.h"

inline void Error(const char* msg) {
    #ifdef DEBUG_MODE
    puts("ERROR: ");
    puts(msg);
    #endif
    for (;;) {}
}

inline void Print(const char* msg) {
    #ifdef DEBUG_MODE
    puts(msg);
    #endif
}

inline void PrintFmt(const char* fmt...) {
    #ifdef DEBUG_MODE
    printf(fmt);
    #endif
}