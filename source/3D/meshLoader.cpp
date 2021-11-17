#include <fstream>
#include <string.h>
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

void MeshLoader::loadMeshes()
{
    // read menifest file
    std::ifstream manifest;
    manifest.open("./meshes/manifest");

    std::string buf;
    do
    {
        manifest >> buf;
        Console::print("Loading mesh: " + buf);

        std::ifstream meshFile("./meshes/" + buf + ".mesh", std::ios::binary);

        Mesh proto;

        int vertexAmount;
        ri(&meshFile, &vertexAmount);
        Console::print("verts: " + std::to_string(vertexAmount));

        for (int i = 0; i < vertexAmount; i++)
        {
            point3 pos;
            point2 texCoord;
            rf(&meshFile, &pos.x); rf(&meshFile, &pos.y); rf(&meshFile, &pos.z);
            rf(&meshFile, &texCoord.x); rf(&meshFile, &texCoord.y);
#if DEBUG_MODE
            Console::print("Vert");
            Console::print("    Pos " + std::to_string(pos.x) + " " + std::to_string(pos.y) + " " + std::to_string(pos.z));
            Console::print("    Tex Coord " + std::to_string(texCoord.x) + " " + std::to_string(texCoord.y));
#endif
            proto.verts.push_back((vertex){ pos, texCoord });
        }

        int faceAmount;
        ri(&meshFile, &faceAmount);
        Console::print("faces: " + std::to_string(faceAmount));

        for (int i = 0; i < faceAmount; i++)
        {
            int pointer[3] = { 0, 0, 0 };
            point3 dir;
            ri(&meshFile, &pointer[0]); ri(&meshFile, &pointer[1]); ri(&meshFile, &pointer[2]);
            rf(&meshFile, &dir.x); rf(&meshFile, &dir.y); rf(&meshFile, &dir.z);
#if DEBUG_MODE
            Console::print("Face");
            Console::print("    Pointers " + std::to_string(pointer[0]) + " " + std::to_string(pointer[1]) + " " + std::to_string(pointer[2]));
            Console::print("    Look Dir " + std::to_string(dir.x) + " " + std::to_string(dir.y) + " " + std::to_string(dir.z));
#endif
            proto.faces.push_back((face){ {
                &proto.verts[pointer[0]],
                &proto.verts[pointer[1]],
                &proto.verts[pointer[2]]
            }, dir });
        }

        Meshes[buf] = proto;
        meshFile.close();

        Console::print("Done!");
    }
    while (!manifest.eof());

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