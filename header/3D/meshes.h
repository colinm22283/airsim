#pragma once

#include <string>

#include <3D/mesh.h>

namespace Meshes
{
    extern int count;
    extern char** names;
    extern mesh** meshes;

    extern mesh* get(std::string name);
}