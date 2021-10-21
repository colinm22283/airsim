#include <vector>

#include "../header/menu.h"
#include "render.h"

Menu::Menu()
{
    elements = (element*)malloc(0);
    elementCount = 0;
    posX = 0;
    posY = 0;
    w = 0;
    h = 0;
}
Menu::Menu(std::vector<element> _elements, int _posX, int _posY, int _w, int _h)
{
    elements = (element*)malloc(sizeof(element) * _elements.size());
    for (int i = 0; i < (int)_elements.size(); i++)
    {
        elements[i] = _elements[i];
    }
    elementCount = _elements.size();

    posX = _posX;
    posY = _posY;
    w = _w;
    h = _h;
}

void Menu::update()
{
    Render::drawRect(posX, posY, w, h);
}