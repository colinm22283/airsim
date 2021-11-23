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
#include <3D/meshes.h>

void Script::exit()
{
    Console::print("Exit");

    Engine::quit = true;
}

void Script::keyDown(SDL_Keysym keysym) { }

// Mesh block;
// Mesh pyr;
void Script::start()
{
    Object o1({ 20, 0, 20 }, { 0, 0, 0 }, { 5, 5, 5 }, Meshes::get("cube"));
    Engine3DGlobal::objects.push_back(o1);

    Engine3DGlobal::camera.pos.y = 3;
}

void Script::update()
{
    Render::clearScreen({ 0, 0, 0 });
    
    Engine3DGlobal::camera.dir.y = fmodf32(Input::mouseVelX / 150.0f + Engine3DGlobal::camera.dir.y, PI * 2);
    Engine3DGlobal::camera.dir.x = fmodf32(Input::mouseVelY / 150.0f + Engine3DGlobal::camera.dir.x, PI * 2);

    if(Input::getKey(119))
    {
        Engine3DGlobal::camera.pos.x += cosf32(Engine3DGlobal::camera.dir.y) * 0.005f * Engine::deltaTime;
        Engine3DGlobal::camera.pos.z += sinf32(Engine3DGlobal::camera.dir.y) * 0.005f * Engine::deltaTime;
    }
    if(Input::getKey(115))
    {
        Engine3DGlobal::camera.pos.x -= cosf32(Engine3DGlobal::camera.dir.y) * 0.005f * Engine::deltaTime;
        Engine3DGlobal::camera.pos.z -= sinf32(Engine3DGlobal::camera.dir.y) * 0.005f * Engine::deltaTime;
    }
    if(Input::getKey(97))
    {
        Engine3DGlobal::camera.dir.y = fmodf32(Engine3DGlobal::camera.dir.y - 0.002f, PI * 2);
    }
    if(Input::getKey(100))
    {
        Engine3DGlobal::camera.dir.y = fmodf32(Engine3DGlobal::camera.dir.y + 0.002f, PI * 2);
    }

    Engine3DGlobal::camera.dir.y = Engine3DGlobal::camera.dir.y < 0 ? PI * 2 + Engine3DGlobal::camera.dir.y : Engine3DGlobal::camera.dir.y;
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