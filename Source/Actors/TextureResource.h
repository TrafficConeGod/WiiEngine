#pragma once
#include "Resource.h"

class TextureResource : public virtual Resource {
    public:
        static const short ID = 6;

        using Resource::Resource;
        virtual void Load(DataStream& stream);
};