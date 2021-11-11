#include <input.h>

bool Input::mouseLeft = false;
bool Input::mouseMiddle = false;
bool Input::mouseRight = false;
int Input::mouseX = 0;
int Input::mouseY = 0;
int Input::mouseVelX = 0;
int Input::mouseVelY = 0;

bool mouseInit = false;
int prevMouseX = 0;
int prevMouseY = 0;

void Input::initMouse()
{
    if (!mouseInit)
    {
        mouseInit = true;

        prevMouseX = Input::mouseX;
        prevMouseY = Input::mouseY;
    }
}

void Input::update()
{
    if (mouseInit)
    {
        Input::mouseVelX = Input::mouseX - prevMouseX;
        Input::mouseVelY = Input::mouseY - prevMouseY;
        prevMouseX = Input::mouseX;
        prevMouseY = Input::mouseY;
    }
}