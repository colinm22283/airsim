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
#include "obj.h"

#include "sim.h"
#include "simFlags.h"

void Script::exit()
{
    Console::print("Exit");

    Engine::quit = true;
}

void Script::keyDown(SDL_Keysym keysym) { }

object o;

void Script::start()
{
    Sim::start();

    o = object({ 255, 0, 0, 255 });

    o.points.push_back({ 300, 150 });
    o.points.push_back({ 230, 175 });
    o.points.push_back({ 200, 200 });
    o.points.push_back({ 230, 225 });
    o.points.push_back({ 300, 250 });

    Sim::objects.push_back(o);

    Global::fpsLimit = 60;
    Global::fpsOutput = true;
}
void Script::update()
{
    Render::clearScreen({ 255, 255, 255, 255 });

    Sim::update();
    Sim::render();

    o.draw();
}

void Script::mouseDown(int button)
{
    
}
void Script::mouseClick(int button)
{
    
}

bool Script::consoleSet(std::string variable, std::string value)
{
    if (variable == "debugmode") SimFlags::debugMode = value == "true" ? true : false;
    else if (variable == "velocityvectors") SimFlags::drawVelocityVectors = value == "true" ? true : false;
    else if (variable == "forcevectors") SimFlags::drawForceVectors = value == "true" ? true : false;
    else if (variable == "spawninterval") SimFlags::spawnInterval = std::stol(value);
    else if (variable == "lifespan") SimFlags::particleLifespan = std::stol(value);
    else return false;

    return true;
}