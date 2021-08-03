#include "World.h"
#include "actors/BouncingBall.h"
#include "actors/Character.h"
#include "wii/io.h"
#include "templates.h"

World::~World() {
    for (size_t i = 0; i < actors.size; i++) {
        delete actors[i];
    }
}

Actor* World::AllocateActor(ushort id) {
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

Actor* World::LoadActor(DataStream& stream) {
    ushort id = 0;
    // stream >> id;

    auto actor = AllocateActor(id);
    actor->Load(stream);

    return actor;
}

void World::LoadActors(DataStream& stream) {
    // while (stream.IsReadable()) {
    //     LoadActor(stream);
    // }
}

void World::DoAction(void (*action)(Actor*)) {
    for (size_t i = 0; i < actors.size; i++) {
        auto actor = actors[i];
        action(actor);
    }
}