#include "TextureResource.h"

bool TextureResource::IsOfType(short id) {
    return id == ID || Resource::IsOfType(id);
}

void TextureResource::Load(DataStream& stream) {
    Resource::Load(stream);
    Print(path);
}