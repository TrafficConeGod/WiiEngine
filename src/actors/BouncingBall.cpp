#include "BouncingBall.h"

bool BouncingBall::IsOfType(ushort id) {
    return Sprite::IsOfType(id) || id == BouncingBall::ID;
}

void BouncingBall::Create() {
	Sprite::Create();
    x = rand() % (640 - 32) << 8;
	y = rand() % (480 - 32) << 8 ;
	dx = (rand() & 0xFF) + 0x100;
	dy = (rand() & 0xFF) + 0x100;
	image = rand() & 3;

	if (rand() & 1) {
		dx = -dx;
    }
	if (rand() & 1) {
		dy = -dy;
    }
}

void BouncingBall::Update() {
	Sprite::Update();
    x += dx;
	y += dy;

	if(x < (1 << 8) || x > ((640 - 32) << 8)) {
		dx = -dx;
    }

	if(y < (1 << 8) || y > ((480 - 32) << 8)) {
		dy = -dy;
    }
}