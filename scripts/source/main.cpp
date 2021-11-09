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

void Script::exit()
{
    Console::print("Exit");

    Engine::quit = true;
}

void Script::keyDown(SDL_Keysym keysym) { }

Mesh m;
Object o;

void Script::start()
{
    m = Mesh::createBlock(10, 10, 10);
    o.pos = { 20, 0, 20 };
    o.mesh = &m;
    Engine3DGlobal::objects.push_back(o);

    Engine3DGlobal::camera.pos.y = 3;
}
void Script::update()
{
    Render::clearScreen({ 0, 0, 0 });
    Engine3DGlobal::objects[0].draw();
    Engine3DGlobal::camera.dir.y += 0.001;
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