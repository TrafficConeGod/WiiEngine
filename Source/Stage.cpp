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
            actor = dynamic_cast<Actor*>(new BouncingBall(this));
            break;
        case Character::ID:
            actor = dynamic_cast<Actor*>(new Character(this));
            break;
        default:
            return nullptr;
    }
    actors.Push(actor);
    return actor;
}

Actor* Stage::LoadActor(DataStream& stream) {
    ushort id = 0;
    stream >> id;

    printf("Loaded Actor ID: %d\n", id);

    auto actor = AllocateActor(id);
    actor->Load(stream);
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