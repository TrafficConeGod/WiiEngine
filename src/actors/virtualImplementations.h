#pragma once
#include "Actor.h"
#include "interfaces/ISprite.h"
#include "interfaces/IInputtable.h"

#define IMPLEMENT_VIRTUAL(name) struct name : public Actor, public I##name { using Actor::Actor; };

IMPLEMENT_VIRTUAL(Sprite)
IMPLEMENT_VIRTUAL(Inputtable)