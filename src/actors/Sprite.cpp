#include "Sprite.h"
#include "../wii/io.h"

void Sprite::Create() {
	Actor::Create();
    x = rand() % (640 - 32) << 8;
	y = rand() % (480 - 32) << 8 ;
	dx = (rand() & 0xFF) + 0x100;
	dy = (rand() & 0xFF) + 0x100;
	image = rand() & 3;

	if(rand() & 1)
		dx = -dx;
	if(rand() & 1)
		dy = -dy;
}

void Sprite::Update() {
	Actor::Update();
    x += dx;
	y += dy;

	if(x < (1 << 8) || x > ((640 - 32) << 8)) {
		dx = -dx;
    }

	if(y < (1 << 8) || y > ((480 - 32) << 8)) {
		dy = -dy;
    }
}

float texCoords[] = {
	0.0, 0.0,  0.5, 0.0, 0.5, 0.5, 0.0, 0.5,
	0.5, 0.0,  1.0, 0.0, 1.0, 0.5, 0.5, 0.5,
	0.0, 0.5,  0.5, 0.5, 0.5, 1.0, 0.0, 1.0,
	0.5, 0.5,  1.0, 0.5, 1.0, 1.0, 0.5, 1.0
};


void Sprite::Draw() {
	const int width = 32;
	const int height = 32;
	int drawX = x >> 8;
	int drawY = y >> 8;

	int texIndex = image * 8;

	GX_Begin(GX_QUADS, GX_VTXFMT0, 4);			// Draw A Quad
	GX_Position2f32(drawX, drawY);					// Top Left
	GX_TexCoord2f32(texCoords[texIndex], texCoords[texIndex + 1]);
	texIndex += 2;
	GX_Position2f32(drawX + width - 1, drawY);			// Top Right
	GX_TexCoord2f32(texCoords[texIndex], texCoords[texIndex + 1]);
	texIndex += 2;
	GX_Position2f32(drawX + width - 1, drawY + height - 1);	// Bottom Right
	GX_TexCoord2f32(texCoords[texIndex], texCoords[texIndex + 1]);
	texIndex += 2;
	GX_Position2f32(drawX, drawY + height - 1);			// Bottom Left
	GX_TexCoord2f32(texCoords[texIndex], texCoords[texIndex + 1]);
	GX_End();
}