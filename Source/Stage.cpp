#include "Stage.h"
#include "Actors/BouncingBall.h"
#include "Actors/Character.h"
#include "Wii/io.h"

Stage::~Stage() {
    for (size_t i = 0; i < actors.size; i++) {
        free(actors[i]);
    }
}

Actor* Stage::AllocateActor(ushort id) {
    Actor* actor;
    switch (id) {
        case Actor::ID:
            actor = new Actor(this);
            break;
        case BouncingBall::ID:
            actor = new BouncingBall(this);
            break;
        case Character::ID:
            actor = new Character(this);
            break;
        default:
            puts("Invalid actor id");
            exit(0);
            break;
    }
    actors.Push(actor);
    return actor;
}

Actor* Stage::LoadActor(DataStream& stream) {
    ushort id = 0;
    stream >> id;

    auto actor = AllocateActor(id);
    actor->Load(stream);
    actors.Push(actor);
    return actor;
}

void Stage::LoadActors(DataStream& stream) {
    while (stream.IsReadable()) {
        LoadActor(stream);
    }
}

void Stage::DoAction(void (*action)(Actor*)) {
    for (size_t i = 0; i < actors.size; i++) {
        auto actor = actors[i];
        action(actor);
    }
}