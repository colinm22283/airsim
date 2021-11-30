#include <string>
#include <map>

#include <3D/meshes.h>
#include <3D/mesh.h>

int Meshes::count = 0;
char** Meshes::names;
mesh** Meshes::meshes = NULL;

mesh* Meshes::get(std::string name)
{
    for (int i = 0; i < Meshes::count; i++)
    {
        if (Meshes::names[i] == name)
        {
            return Meshes::meshes[i];
        }
    }
    return NULL;
}