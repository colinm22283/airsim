#include "SDL/SDL.h"
#include <iostream>

#include "script.h"
#include "event.h"
#include "console.h"
#include "consoleParser.h"
#include "engine.h"
#include "input.h"
#include "global.h"
#include "titlebar.h"

SDL_Event Event::event;

void Event::init()
{
    while (!Engine::quit)
    {
        Event::update();
    }
}
void Event::update()
{
    if (SDL_PollEvent(&event) != 0)
    {
        switch (event.type)
        {
        case SDL_QUIT:
            Script::exit();
            break;
        case SDL_KEYDOWN:
        {
            int ck = event.key.keysym.sym;
            if (ck < KEY_MAX) Input::keys[ck] = true;

            switch (event.key.keysym.mod)
            {
            case KMOD_SHIFT:
                Input::modifiers::shift = true;
                break;
            case KMOD_CTRL:
                Input::modifiers::ctrl = true;
                break;
            case KMOD_ALT:
                Input::modifiers::alt = true;
                break;
            case KMOD_LSHIFT:
                Input::modifiers::lshift = true;
                break;
            case KMOD_LCTRL:
                Input::modifiers::lctrl = true;
                break;
            case KMOD_LALT:
                Input::modifiers::lalt = true;
                break;
            case KMOD_RSHIFT:
                Input::modifiers::rshift = true;
                break;
            case KMOD_RCTRL:
                Input::modifiers::rctrl = true;
                break;
            case KMOD_RALT:
                Input::modifiers::ralt = true;
                break;
            }

            ConsoleParser::keyDown(event.key.keysym);
            Console::keyDown(event.key.keysym);
            Script::keyDown(event.key.keysym);
            if (Global::printKeys) Console::print("Key: " + std::to_string(event.key.keysym.sym));
        } break;
        case SDL_KEYUP:
        {
            int ck = event.key.keysym.sym;
            if (ck < KEY_MAX) Input::keys[ck] = false;

            switch (event.key.keysym.mod)
            {
            case KMOD_SHIFT:
                Input::modifiers::shift = false;
                break;
            case KMOD_CTRL:
                Input::modifiers::ctrl = false;
                break;
            case KMOD_ALT:
                Input::modifiers::alt = false;
                break;
            case KMOD_LSHIFT:
                Input::modifiers::lshift = false;
                break;
            case KMOD_LCTRL:
                Input::modifiers::lctrl = false;
                break;
            case KMOD_LALT:
                Input::modifiers::lalt = false;
                break;
            case KMOD_RSHIFT:
                Input::modifiers::rshift = false;
                break;
            case KMOD_RCTRL:
                Input::modifiers::rctrl = false;
                break;
            case KMOD_RALT:
                Input::modifiers::ralt = false;
                break;
            }
        } break;
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&Input::mouseX, &Input::mouseY);
            Input::initMouse();
            break;
        case SDL_MOUSEBUTTONDOWN:
        {
            switch (event.button.button)
            {
            case SDL_BUTTON_LEFT:
                Input::mouseLeft = true;
                break;
            case SDL_BUTTON_MIDDLE:
                Input::mouseMiddle = true;
                break;
            case SDL_BUTTON_RIGHT:
                Input::mouseRight = true;
                break;
            break;
            }
        }
        break;
        case SDL_MOUSEBUTTONUP:
        {
            Script::mouseClick(event.button.button);
            Titlebar::mouseClick(event.button.button);

            switch (event.button.button)
            {
            case SDL_BUTTON_LEFT:
                Input::mouseLeft = false;
                break;
            case SDL_BUTTON_MIDDLE:
                Input::mouseMiddle = false;
                break;
            case SDL_BUTTON_RIGHT:
                Input::mouseRight = false;
                break;
            break;
            }
        }
        break;
        }
    }

    if (Input::mouseLeft) Script::mouseDown(SDL_BUTTON_LEFT);
    if (Input::mouseMiddle) Script::mouseDown(SDL_BUTTON_MIDDLE);
    if (Input::mouseRight) Script::mouseDown(SDL_BUTTON_RIGHT);
}