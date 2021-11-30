#include <string>

#include <3D/textures.h>
#include <3D/texture.h>

int Textures::count;
char** Textures::names;
texture** Textures::textures;

texture* Textures::get(std::string name)
{
    for (int i = 0; i < Textures::count; i++)
    {
        if (Textures::names[i] == name)
        {
            return Textures::textures[i];
        }
    }
    return NULL;
}