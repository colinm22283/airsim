#include <vector>
#include <fstream>
#include <string>
#include <regex>

#include <global.h>
#include <console.h>
#include <misc.h>

#include <3D/textureLoader.h>
#include <3D/texture.h>
#include <3D/textures.h>

std::vector<texture> textures;
std::vector<std::string> tnames;

void TextureLoader::loadTextures()
{
    std::ifstream manifest("./textures/manifest");
    
    int line = 0;
    std::regex rgx("\\/?([^\\/\\.]*)\\.texture");
    std::string buf;
    do
    {
        line++;

        manifest >> buf;

        std::smatch matches;
        if (std::regex_search(buf, matches, rgx))
        {
            std::string name = matches[1];

            Console::print("Loading texture: " + name + ".texture");

            std::ifstream texFile("./textures/" + name + ".texture", std::ios::binary);

            texture proto;

            ri(&texFile, &proto.width); ri(&texFile, &proto.height);

#if DEV_MODE
            Console::print("    Width: " + std::to_string(proto.width));
            Console::print("    Height: " + std::to_string(proto.height));
#endif

            proto.pixels = (color**)malloc(sizeof(color*) * proto.width);

            for (int x = 0; x < proto.width; x++)
            {
                proto.pixels[x] = (color*)malloc(sizeof(color) * proto.height);

                for (int y = 0; y < proto.height; y++)
                {

                    color c = { 0, 0, 0, 0 };
                    rb(&texFile, &c.r); rb(&texFile, &c.g); rb(&texFile, &c.b);

#if DEV_MODE
                    Console::print("    Pixel: " + std::to_string(c.r) + " " + std::to_string(c.g) + " " + std::to_string(c.b) + " " + std::to_string(c.a));
#endif

                    proto.pixels[x][y] = c;
                }
            }

            tnames.push_back(name);
            textures.push_back(proto);

            texFile.close();
        }
    }
    while (!manifest.eof());

    Textures::textures = (texture**)malloc(sizeof(texture*) * line);
    Textures::names = (char**)malloc(sizeof(char*) * line);
    Textures::count = line;
    for (int i = 0; i < (int)textures.size(); i++)
    {
        Textures::names[i] = (char*)tnames[i].c_str();
        Textures::textures[i] = &textures[i];
    }

    manifest.close();

    Console::print("Done loading textures.");
}