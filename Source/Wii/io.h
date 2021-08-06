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

void Error(const char* msg);
void Print(const char* msg);
void PrintFmt(const char* fmt...);