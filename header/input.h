#pragma once

#define KEY_MAX 256

namespace Input
{
    extern bool mouseLeft;
    extern bool mouseMiddle;
    extern bool mouseRight;
    extern int mouseX;
    extern int mouseY;
    extern int mouseVelX;
    extern int mouseVelY;
    extern bool keys[256];
    namespace modifiers
    {
        extern bool shift;
        extern bool ctrl;
        extern bool alt;
        extern bool lshift;
        extern bool lctrl;
        extern bool lalt;
        extern bool rshift;
        extern bool rctrl;
        extern bool ralt;
    }
    
    extern void initMouse();
    extern void update();

    extern bool getKey(int keyCode);
}