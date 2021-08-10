#include "Stage.h"
#include "Actors/BouncingBall.h"
#include "Actors/Character.h"
#include "Actors/BouncingBallGenerator.h"
#include "Wii/io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define ActorCase(T) case T::ID: \
actor = dynamic_cast<Actor*>(new T(this)); \
break

Stage::~Stage() {
    Destroy();
    for (size_t i = 0; i < actors.size; i++) {
        free(actors[i]);
    }
}

Actor* Stage::AllocateActor(ushort id) {
    Actor* actor;
    switch (id) {
        ActorCase(BouncingBall);
        ActorCase(Character);
        ActorCase(BouncingBallGenerator);
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

bool Stage::LoadFromFile(const char* path) {
    if (access(path, F_OK) != 0) {
        Print("File not found");
		return false;
	}

	FILE* file = fopen(path, "rb");

	fseek(file, 0L, SEEK_END);
	size_t size = ftell(file);
	rewind(file);
	char buf[size];
	fgets(buf, size, file);

	DataStream stream(buf, size);
	LoadActors(stream);
    return true;
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