#include <fstream>
#include <string.h>
#include <regex>
#include <vector>
#include <iostream>

#include <global.h>
#include <console.h>

#include <3D/meshLoader.h>
#include <3D/meshes.h>
#include <3D/mesh.h>

void wi(std::ofstream* s, int x);
void wf(std::ofstream* s, float x);
void ri(std::ifstream* s, int* x);
void rf(std::ifstream* s, float* x);

std::vector<Mesh> meshes;

void MeshLoader::loadMeshes()
{
    std::ifstream manifest;
    manifest.open("./meshes/manifest");

    std::vector<std::string> names;

    int line = 0;
    std::regex rgx("\\/([^\\/\\.]*)\\.mesh");
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

            Mesh proto;

            int vertexAmount;
            ri(&meshFile, &vertexAmount);
            Console::print("    Verts: " + std::to_string(vertexAmount));

            for (int i = 0; i < vertexAmount; i++)
            {
                point3 pos;
                point2 texCoord;
                rf(&meshFile, &pos.x); rf(&meshFile, &pos.y); rf(&meshFile, &pos.z);
                rf(&meshFile, &texCoord.x); rf(&meshFile, &texCoord.y);
#if DEBUG_MODE
                Console::print("    Vert");
                Console::print("        Pos " + std::to_string(pos.x) + " " + std::to_string(pos.y) + " " + std::to_string(pos.z));
                Console::print("        Tex Coord " + std::to_string(texCoord.x) + " " + std::to_string(texCoord.y));
#endif
                proto.verts.push_back((vertex){ pos, texCoord });
            }

            int faceAmount;
            ri(&meshFile, &faceAmount);
            Console::print("    Faces: " + std::to_string(faceAmount));

            for (int i = 0; i < faceAmount; i++)
            {
                int pointer[3] = { 0, 0, 0 };
                point3 dir;
                ri(&meshFile, &pointer[0]); ri(&meshFile, &pointer[1]); ri(&meshFile, &pointer[2]);
                rf(&meshFile, &dir.x); rf(&meshFile, &dir.y); rf(&meshFile, &dir.z);
#if DEBUG_MODE
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

#if DEBUG_MODE
            Console::print("\"" + name + "\" loaded");
#endif

            names.push_back(name);
            meshes.push_back(proto);
            meshFile.close();
        }
        else Console::print("Error reading line " + std::to_string(line + 1) + "of meshes manifest.");
        
    }
    while (!manifest.eof());

    Meshes::meshes = (Mesh**)malloc(sizeof(Mesh*) * line);
    Meshes::names = (char**)malloc(sizeof(char*) * line);
    Meshes::count = line;
    for (int i = 0; i < (int)meshes.size(); i++)
    {
        Meshes::names[i] = (char*)names[i].c_str();
        Meshes::meshes[i] = &(meshes[i]);
    }

    Console::print("Done loading meshes.");

    manifest.close();
}

void wi(std::ofstream* s, int x)
{
    char buf[4];
    std::copy(
        static_cast<const char*>(static_cast<const void*>(&x)),
        static_cast<const char*>(static_cast<const void*>(&x)) + 4,
        buf
    );
    for (int i = 0; i < 4; i++) *s << buf[i];
}
void wf(std::ofstream* s, float x)
{
    char buf[4];
    std::copy(
        static_cast<const char*>(static_cast<const void*>(&x)),
        static_cast<const char*>(static_cast<const void*>(&x)) + sizeof(x),
        buf
    );
    for (int i = 0; i < 4; i++) *s << buf[i];
}
void ri(std::ifstream* s, int* x)
{
    char buf[4];
    for (int i = 0; i < 4; i++) s->read(&buf[i], 1);

    memcpy(x, &buf, 4);
}
void rf(std::ifstream* s, float* x)
{
    char buf[4];
    for (int i = 0; i < 4; i++) *s >> buf[i];
    
    memcpy(x, &buf, 4);
}