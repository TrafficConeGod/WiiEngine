#include "TextureResource.h"
// #include "../Build/BasicTexture_tpl.h"

TextureResource* currentTexture = nullptr;

bool TextureResource::IsOfType(short id) {
    return id == ID || Resource::IsOfType(id);
}

void TextureResource::Load(DataStream& stream) {
    Resource::Load(stream);
    TPLFile tplFile;
	// TPL_OpenTPLFromMemory(&tplFile, (void*)BasicTexture_tpl, BasicTexture_tpl_size);
	TPL_OpenTPLFromFile(&tplFile, path);
	TPL_GetTexture(&tplFile, 0, &texObj);
}

void TextureResource::UseTexture() {
    #ifdef GFX_MODE
    if (currentTexture == this) {
        return;
    }
    currentTexture = this;
	GX_LoadTexObj(&texObj, GX_TEXMAP0);
    #endif
}