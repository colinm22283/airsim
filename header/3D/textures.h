#pragma once

#include <string>

#include <3D/texture.h>

namespace Textures
{
    extern int count;
    extern char** names;
    extern texture** textures;

    extern texture* get(std::string name);
}