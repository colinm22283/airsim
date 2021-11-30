#pragma once

#include <string>

#include "SDL/SDL.h"

namespace Script
{
    void start();
    void update();
    void keyDown(SDL_Keysym keysym);
    void mouseDown(int button);
    void mouseClick(int button);
    void exit();

    bool consoleSet(std::string variable, std::string value);
}