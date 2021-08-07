#include "Stage.h"
#include "Actors/BouncingBall.h"
#include "Actors/Character.h"
#include "Actors/BouncingBallGenerator.h"
#include "Wii/io.h"

Stage::~Stage() {
    Destroy();
    for (size_t i = 0; i < actors.size; i++) {
        free(actors[i]);
    }
}

Actor* Stage::AllocateActor(ushort id) {
    Actor* actor;
    switch (id) {
        case BouncingBall::ID:
            actor = dynamic_cast<Actor*>(new BouncingBall(this));
            break;
        case Character::ID:
            actor = dynamic_cast<Actor*>(new Character(this));
            break;
        case BouncingBallGenerator::ID:
            actor = dynamic_cast<Actor*>(new BouncingBallGenerator(this));
            break;
        default:
            Error("Invalid Actor ID");
            return nullptr;
    }
    actors << actor;
    return actor;
}

Actor* Stage::LoadActor(DataStream& stream) {
    ushort id = 0;
    stream >> id;

    PrintFmt("Loaded Actor ID: %d\n", id);

    auto actor = AllocateActor(id);
    actor->Load(stream);
    return actor;
}

void Stage::LoadActors(DataStream& stream) {
    while (stream.IsReadable()) {
        LoadActor(stream);
    }
}

void Stage::Initialize() {
    for (size_t i = 0; i < actors.size; i++) {
        auto actor = actors[i];
        actor->Initialize();
    }
}

void DestroyAction(Actor* actor) {
    actor->Destroy();
}

void Stage::Destroy() {
    UseActors(DestroyAction);
}

void Stage::UseActors(void (*func)(Actor*)) {
    for (size_t i = 0; i < actors.size; i++) {
        auto actor = actors[i];
        actor->Use(func);
    }
}