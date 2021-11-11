#pragma once

namespace Input
{
    extern bool mouseLeft;
    extern bool mouseMiddle;
    extern bool mouseRight;
    extern int mouseX;
    extern int mouseY;
    extern int mouseVelX;
    extern int mouseVelY;
    
    extern void initMouse();
    extern void update();
}