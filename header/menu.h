#pragma once

#include <vector>
#include <string>

enum elementType
{ TEXT };
struct element
{
    elementType type;
    std::string text;
    int x;
    int y;
};

class Menu
{
public:
    int posX;
    int posY;
    int w;
    int h;

    Menu();
    Menu(std::vector<element> _elements, int _posX, int _posY, int _w, int _y);

    void update();

//protected:
    element* elements;
    int elementCount;
};