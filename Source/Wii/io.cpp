#include "io.h"

void Error(const char* msg) {
    #ifdef DEBUG_MODE
    puts("ERROR: ");
    puts(msg);
    #endif
    for (;;) {}
}

void Print(const char* msg) {
    #ifdef DEBUG_MODE
    puts(msg);
    #endif
}

void PrintFmt(const char* fmt...) {
    #ifdef DEBUG_MODE
    printf(fmt);
    #endif
}