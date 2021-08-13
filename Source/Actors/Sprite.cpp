#include "Sprite.h"
#include "Wii/io.h"

bool Sprite::IsOfType(short id) {
	return id == ID || Actor::IsOfType(id);
}

void Sprite::Load(DataStream& stream) {
	Actor::Load(stream);
	stream >> pos;
	textureRef.Load(stage, stream);
}

float texCoords[] = {
	0.0, 0.0,  0.5, 0.0, 0.5, 0.5, 0.0, 0.5,
	0.5, 0.0,  1.0, 0.0, 1.0, 0.5, 0.5, 0.5,
	0.0, 0.5,  0.5, 0.5, 0.5, 1.0, 0.0, 1.0,
	0.5, 0.5,  1.0, 0.5, 1.0, 1.0, 0.5, 1.0
};

void Sprite::Draw() {
	#ifdef GFX_MODE
	TextureResource* texture = textureRef;
	if (texture == nullptr) {
		return;
	}
	texture->UseTexture();
	const int width = 32;
	const int height = 32;
	int x = pos.x >> 8;
	int y = pos.y >> 8;

	int texIndex = 0 * 8;

	GX_Begin(GX_QUADS, GX_VTXFMT0, 4);			// Draw A Quad
	GX_Position2f32(x, y);					// Top Left
	GX_TexCoord2f32(texCoords[texIndex], texCoords[texIndex + 1]);
	texIndex += 2;
	GX_Position2f32(x + width - 1, y);			// Top Right
	GX_TexCoord2f32(texCoords[texIndex], texCoords[texIndex + 1]);
	texIndex += 2;
	GX_Position2f32(x + width - 1, y + height - 1);	// Bottom Right
	GX_TexCoord2f32(texCoords[texIndex], texCoords[texIndex + 1]);
	texIndex += 2;
	GX_Position2f32(x, y + height - 1);			// Bottom Left
	GX_TexCoord2f32(texCoords[texIndex], texCoords[texIndex + 1]);
	GX_End();
	#endif
}