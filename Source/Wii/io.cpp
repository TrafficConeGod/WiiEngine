#include "io.h"

void Error(const char* msg) {
    #ifdef DEBUG_MODE
    puts("ERROR: ");
    puts(msg);
    #endif
    for (;;) {
		WPAD_ScanPads();
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) {
			exit(0);
		}
    }
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