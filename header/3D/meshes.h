#pragma once

#include <string>
#include <map>

#include <3D/mesh.h>

namespace Meshes
{
    extern int count;
    extern char** names;
    extern Mesh** meshes;

    extern Mesh* get(std::string name);
}