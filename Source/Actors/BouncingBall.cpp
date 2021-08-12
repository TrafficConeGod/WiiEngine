#include "BouncingBall.h"

bool BouncingBall::IsOfType(short id) {
    return id == ID || Sprite::IsOfType(id);
}

void BouncingBall::Load(DataStream& stream) {
	Sprite::Load(stream);
	stream >> vel;
}

void BouncingBall::Create() {
	Sprite::Create();
	PrintFmt("Bouncing ball create %d\n", rand());
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