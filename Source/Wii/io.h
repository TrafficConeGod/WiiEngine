#pragma once
#include "debug.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <ogc/tpl.h>

inline void Error(const char* msg);
inline void Print(const char* msg);
inline void PrintFmt(const char* fmt...);

#include "io.inl"