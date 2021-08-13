#include "Sprite.h"
#include "Wii/io.h"

bool Sprite::IsOfType(short id) {
	return id == ID || Actor::IsOfType(id);
}

void Sprite::Load(DataStream& stream) {
	Actor::Load(stream);
	stream >> pos;
	stream >> size;
	textureRef.Load(stage, stream);
}

void Sprite::Draw() {
	#ifdef GFX_MODE
	TextureResource* texture = textureRef;
	if (texture == nullptr) {
		return;
	}
	texture->UseTexture();

	GX_Begin(GX_QUADS, GX_VTXFMT0, 4);			// Draw A Quad
	GX_Position2f32(pos.x, pos.y);					// Top Left
	GX_TexCoord2f32(0, 0);
	GX_Position2f32(pos.x + size.x - 1, pos.y);			// Top Right
	GX_TexCoord2f32(0.5, 0);
	GX_Position2f32(pos.x + size.x - 1, pos.y + size.y - 1);	// Bottom Right
	GX_TexCoord2f32(0.5, 0.5);
	GX_Position2f32(pos.x, pos.y + size.y - 1);			// Bottom Left
	GX_TexCoord2f32(0, 0.5);
	GX_End();
	#endif
}