#include <fstream>
#include <string.h>
#include <regex>
#include <vector>

#include <global.h>
#include <console.h>
#include <misc.h>

#include <3D/meshLoader.h>
#include <3D/meshes.h>
#include <3D/mesh.h>

std::vector<mesh> meshes;
std::vector<std::string> mnames;

void MeshLoader::loadMeshes()
{
    std::ifstream manifest;
    manifest.open("./meshes/manifest");

    int line = 0;
    std::regex rgx("\\/?([^\\/\\.]*)\\.mesh");
    std::string buf;
    do
    {
        line++;

        manifest >> buf;

        std::smatch matches;
        if (std::regex_search(buf, matches, rgx))
        {
            std::string name = matches[1];

            Console::print("Loading mesh: " + name + ".mesh");

            std::ifstream meshFile("./meshes/" + buf, std::ios::binary);

            mesh proto;

            int vertexAmount;
            ri(&meshFile, &vertexAmount);
#if DEV_MODE
            Console::print("    Verts: " + std::to_string(vertexAmount));
#endif

            for (int i = 0; i < vertexAmount; i++)
            {
                point3 pos;
                point2 texCoord;
                rf(&meshFile, &pos.x); rf(&meshFile, &pos.y); rf(&meshFile, &pos.z);
                rf(&meshFile, &texCoord.x); rf(&meshFile, &texCoord.y);
#if DEV_MODE
                Console::print("    Vert");
                Console::print("        Pos " + std::to_string(pos.x) + " " + std::to_string(pos.y) + " " + std::to_string(pos.z));
                Console::print("        Tex Coord " + std::to_string(texCoord.x) + " " + std::to_string(texCoord.y));
#endif
                proto.verts.push_back((vertex){ pos, texCoord });
            }

            int faceAmount;
            ri(&meshFile, &faceAmount);
#if DEV_MODE
            Console::print("    Faces: " + std::to_string(faceAmount));
#endif

            for (int i = 0; i < faceAmount; i++)
            {
                int pointer[3] = { 0, 0, 0 };
                point3 dir;
                ri(&meshFile, &pointer[0]); ri(&meshFile, &pointer[1]); ri(&meshFile, &pointer[2]);
                rf(&meshFile, &dir.x); rf(&meshFile, &dir.y); rf(&meshFile, &dir.z);
#if DEV_MODE
                Console::print("    Face");
                Console::print("        Pointers " + std::to_string(pointer[0]) + " " + std::to_string(pointer[1]) + " " + std::to_string(pointer[2]));
                Console::print("        Look Dir " + std::to_string(dir.x) + " " + std::to_string(dir.y) + " " + std::to_string(dir.z));
#endif
                proto.faces.push_back((face){ {
                    pointer[0],
                    pointer[1],
                    pointer[2]
                }, dir });
            }

#if DEV_MODE
            Console::print("\"" + name + "\" loaded");
#endif

            mnames.push_back(name);
            meshes.push_back(proto);

            meshFile.close();
        }
        else Console::print("Error reading line " + std::to_string(line + 1) + "of meshes manifest.");
        
    }
    while (!manifest.eof());

    Meshes::meshes = (mesh**)malloc(sizeof(mesh*) * line);
    Meshes::names = (char**)malloc(sizeof(char*) * line);
    Meshes::count = line;
    for (int i = 0; i < (int)meshes.size(); i++)
    {
        Meshes::names[i] = (char*)mnames[i].c_str();
        Meshes::meshes[i] = &meshes[i];
    }

    manifest.close();

    Console::print("Done loading meshes.");
}