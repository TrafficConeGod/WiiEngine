#include "World.h"
#include "actors/Sprite.h"
#include "actors/BouncingBall.h"
#include "wii/io.h"
#include "templates.h"

Actor* World::AllocateActor(ushort id) {
    Actor* actor;
    switch (id) {
        case Actor::ID:
            actor = new Actor(this);
            break;
        case Sprite::ID:
            actor = new Sprite(this);
            break;
        case BouncingBall::ID:
            actor = new BouncingBall(this);
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

void World::DoActionOn(ushort id, void (*action)(Actor*)) {
    for (size_t i = 0; i < actors.size; i++) {
        auto actor = actors[i];
        if (actor->IsOfType(id)) {
            action(actor);
        }
    }
}