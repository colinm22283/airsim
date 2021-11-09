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
    o.pos = { 0, 0, 5 };
    o.mesh = &m;
    Engine3DGlobal::objects.push_back(o);
}
void Script::update()
{
    Engine3DGlobal::objects[0].draw();
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