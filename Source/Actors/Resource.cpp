#include "Resource.h"

void Resource::Load(DataStream& stream) {
    Actor::Load(stream);
    path.Load(stream);
}