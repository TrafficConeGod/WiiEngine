#include "Resource.h"

bool Resource::IsOfType(short id) {
    return id == ID || Actor::IsOfType(id);
}

void Resource::Load(DataStream& stream) {
    Actor::Load(stream);
    path.Load(stream);
}