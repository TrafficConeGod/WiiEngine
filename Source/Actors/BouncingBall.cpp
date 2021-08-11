#include "BouncingBall.h"

bool BouncingBall::IsOfType(short id) {
    return id == ID || Sprite::IsOfType(id);
}

void BouncingBall::Load(DataStream& stream) {
    stream >> pos;
	stream >> vel;
}

void BouncingBall::Create() {
	PrintFmt("Bouncing ball load%d\n", rand());
	Sprite::Create();
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