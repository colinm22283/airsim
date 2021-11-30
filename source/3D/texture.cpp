#include <render.h>

#include <3D/texture.h>

void texture::draw(int _x, int _y)
{
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        { Render::drawPixel(_x + x, _y + y, pixels[x][y]); }
    }
}