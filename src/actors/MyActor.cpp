#include "MyActor.h"
#include "../wii/io.h"

void MyActor::Create() {
    Actor::Create();
    x = 10;
    y = 20;
}