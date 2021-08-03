#include "BouncingBall.h"
#include "templates.h"

bool BouncingBall::IsOfType(ushort id) {
    return id == ID || Sprite::IsOfType(id);
}

void BouncingBall::Create() {
	Sprite::Create();
    pos = Vector2i(rand() % (640 - 32) << 8, rand() % (480 - 32) << 8);
	vel = Vector2i((rand() & 0xFF) + 0x100, (rand() & 0xFF) + 0x100);
	image = rand() & 3;

	if (rand() & 1) {
		vel.x = -vel.x;
    }
	if (rand() & 1) {
		vel.y = -vel.y;
    }
}

void BouncingBall::Update() {
	Sprite::Update();
    pos.x += vel.x;
	pos.y += vel.y;

	if (pos.x < (1 << 8) || pos.x > ((640 - 32) << 8)) {
		vel.x = -vel.x;
    }

	if (pos.y < (1 << 8) || pos.y > ((480 - 32) << 8)) {
		vel.y = -vel.y;
    }
}