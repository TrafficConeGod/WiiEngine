#include "TextureResource.h"

void TextureResource::Load(DataStream& stream) {
    Resource::Load(stream);
    Print(path);
}