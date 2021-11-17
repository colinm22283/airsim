#include <math.h>
#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

#include "global.h"
#include "script.h"
#include "engine.h"
#include "console.h"
#include "render.h"
#include "input.h"
#include "consoleParser.h"
#include "font.h"

#include <3D/engine3DGlobal.h>
#include <3D/object.h>
#include <3D/primatives.h>
#include <3D/meshes.h>

void Script::exit()
{
    Console::print("Exit");

    Engine::quit = true;
}

void Script::keyDown(SDL_Keysym keysym) { }

Mesh block;
Mesh pyr;
void Script::start()
{
    block = Primatives::createBlock(10, 10, 10);
    pyr = Primatives::createPyramid(10, -10, 10);
    Object o1({ 20, 0, 20 }, { 0, 0, 0 }, &Meshes["cube"]);
    Engine3DGlobal::objects.push_back(o1);
    Object o2({ 30, 10, 30 }, { 0, 0, 0 }, &pyr);
    Engine3DGlobal::objects.push_back(o2);

    Engine3DGlobal::camera.pos.y = 3;
}
void Script::update()
{
    Render::clearScreen({ 0, 0, 0 });
    
    Engine3DGlobal::camera.dir.y += Input::mouseVelX / 150.0f;
    Engine3DGlobal::camera.dir.x += Input::mouseVelY / 150.0f;
    if(Input::getKey(119))
    {
        Engine3DGlobal::camera.pos.x += cosf32(Engine3DGlobal::camera.dir.y) * 0.1f;
        Engine3DGlobal::camera.pos.z += sinf32(Engine3DGlobal::camera.dir.y) * 0.1f;
    }
    if(Input::getKey(115))
    {
        Engine3DGlobal::camera.pos.x -= cosf32(Engine3DGlobal::camera.dir.y) * 0.1f;
        Engine3DGlobal::camera.pos.z -= sinf32(Engine3DGlobal::camera.dir.y) * 0.1f;
    }
    // if(Input::getKey(97))
    // {
    //     Engine3DGlobal::camera.pos.x += cosf32(Engine3DGlobal::camera.dir.y) * 0.1f;
    //     Engine3DGlobal::camera.pos.z += sinf32(Engine3DGlobal::camera.dir.y) * 0.1f;
    // }
    // if(Input::getKey(100))
    // {
    //     Engine3DGlobal::camera.pos.x -= cosf32(Engine3DGlobal::camera.dir.y) * 0.1f;
    //     Engine3DGlobal::camera.pos.z -= sinf32(Engine3DGlobal::camera.dir.y) * 0.1f;
    // }
}

void Script::mouseDown(int button)
{
    
}
void Script::mouseClick(int button)
{
    
}

bool Script::consoleSet(std::string variable, std::string value)
{
    return false;
}