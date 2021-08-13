#include "Stage.h"
#include "Actors/TextureResource.h"
#include "Actors/Sprite.h"
#include "Wii/io.h"
#include "Wii/file.h"

#define ActorCase(T) case T::ID: \
actor = dynamic_cast<Actor*>(new T(this)); \
break

Stage::~Stage() {
    Destroy();
    for (size_t i = 0; i < actors.size; i++) {
        free(actors[i]);
    }
}

size_t Stage::GetCurrentIndex() {
    return actors.size;
}

Actor* Stage::AllocateActor(short id) {
    Actor* actor;
    switch (id) {
        ActorCase(Sprite);
        ActorCase(TextureResource);
        default:
            Print("Invalid Actor ID");
            return nullptr;
    }
    actors << actor;
    return actor;
}

Actor* Stage::GetActorAtIndex(size_t index) {
    if (index >= actors.size) {
        return nullptr;
    }
    return actors[index];
}

void Stage::RemoveActor(size_t index) {
    actors[index] = nullptr;
}

Actor* Stage::LoadActor(DataStream& stream) {
    short id = 0;
    stream >> id;

    PrintFmt("Loaded Actor ID: %d\n", id);

    auto actor = AllocateActor(id);
    if (actor == nullptr) {
        return nullptr;
    }
    actor->Load(stream);
    return actor;
}

bool Stage::LoadActors(DataStream& stream) {
    while (stream.IsReadable()) {
        if (LoadActor(stream) == nullptr) {
            return false;
        }
    }
    return true;
}

bool LoadStageFromFileAction(void* buf, size_t size, Stage* stage) {
    DataStream stream(buf, size);
    return stage->LoadActors(stream);
}

bool Stage::LoadFromFile(const char* path) {
    return UseFileWith(path, this, LoadStageFromFileAction);
}

void Stage::Initialize() {
    for (size_t i = 0; i < actors.size; i++) {
        auto actor = actors[i];
        actor->Initialize();
    }
}

static void DestroyAction(Actor* actor) {
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