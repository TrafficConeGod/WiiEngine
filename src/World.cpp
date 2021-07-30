#include "World.h"
#include "actors/MyActor.h"
#include "actors/Sprite.h"
#include "wii/io.h"
#include "templates.h"

Actor& World::AllocateActor(ushort id) {
    Actor* actor_ptr;
    switch (id) {
        case MyActor::ID:
            actor_ptr = new MyActor(*this);
            break;
        case Sprite::ID:
            actor_ptr = new Sprite(*this);
            break;
        default:
            puts("Invalid actor id");
            exit(0);
            break;
    }
    actor_ptr->id = id;
    actor_ptrs.Push(actor_ptr);
    return *actor_ptr;
}

Actor& World::LoadActor(DataStream& stream) {
    ushort id = 0;
    // stream >> id;

    Actor& actor = AllocateActor(id);
    actor.Load(stream);

    return actor;
}

void World::LoadActors(DataStream& stream) {
    // while (stream.IsReadable()) {
    //     LoadActor(stream);
    // }
}

void World::DoAction(void (*action)(Actor&)) {
    for (size_t i = 0; i < actor_ptrs.size; i++) {
        Actor& actor = *actor_ptrs[i];
        action(actor);
    }
}

void World::DoActionOn(ushort id, void (*action)(Actor&)) {
    for (size_t i = 0; i < actor_ptrs.size; i++) {
        Actor& actor = *actor_ptrs[i];
        if (actor.id == id) {
            action(actor);
        }
    }
}