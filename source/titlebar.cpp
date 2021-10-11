#include <vector>

#include "titlebar.h"
#include "font.h"
#include "render.h"
#include "global.h"
#include "console.h"
#include "input.h"

bool Titlebar::enabled = false;
std::vector<Titlebar::Dropdown> Titlebar::dropdowns;
std::vector<int> Titlebar::eventQueue;

void Titlebar::update()
{
    if (Titlebar::enabled && Titlebar::dropdowns.size() > 0)
    {
        Render::fillRect(0, 0, Global::windowWidth, 25, { 0, 0, 0, 255 });
        Render::setColor({ 255, 255, 255, 255 });
        int textPos = 2;
        for (int i = 0; i < (int)Titlebar::dropdowns.size(); i++)
        {
            int textLength = Titlebar::dropdowns[i].name.length() * 13 + 4;

            Render::drawText(textPos, 2, Font::consolas, Titlebar::dropdowns[i].name);
            Render::drawRect(textPos - 2, 0, textLength, 25);

            if (Titlebar::dropdowns[i].open)
            {
                Render::fillRect(
                    textPos - 2,
                    25,
                    textLength,
                    (int)Titlebar::dropdowns[i].buttons.size() * 27,
                    { 0, 0, 0, 255 }
                );
                for (int j = 0; j < (int)Titlebar::dropdowns[i].buttons.size(); j++)
                {
                    Render::drawText(textPos, j * 25 + 27, Font::consolas, Titlebar::dropdowns[i].buttons[j].text);
                }
            }

            textPos += textLength;
        }
    }
}
void Titlebar::mouseClick(int button)
{
    if (button == 1)
    {
        bool temp = false;
        int textPos = 0;
        for (int i = 0; i < (int)Titlebar::dropdowns.size(); i++)
        {
            int textLength = Titlebar::dropdowns[i].name.length() * 13 + 4;

            if (
                Input::mouseX >= textPos && Input::mouseX <= textPos + textLength &&
                Input::mouseY >= 0 && Input::mouseY <= 25
            )
            {
                Titlebar::dropdowns[i].open = !Titlebar::dropdowns[i].open;
                temp = true;
            }

            for (int j = 0; j < (int)Titlebar::dropdowns[i].buttons.size(); j++)
            {
                if (
                    Input::mouseX >= textPos && Input::mouseX <= textPos + textLength &&
                    Input::mouseY >= j * 25 + 27 && Input::mouseY <= j * 25 + 52
                )
                {
                    Titlebar::dropdowns[i].open = false;
                    Titlebar::eventQueue.push_back(Titlebar::dropdowns[i].buttons[j].callId);
                    temp = true;
                }
                Render::drawText(textPos, j * 25 + 27, Font::consolas, Titlebar::dropdowns[i].buttons[j].text);
            }

            textPos += textLength;
        }

        if (!temp)
        {
            for (int i = 0; i < (int)Titlebar::dropdowns.size(); i++)
            { Titlebar::dropdowns[i].open = false; };
        }
    }
}

Titlebar::Dropdown Titlebar::addDropdown(std::string title)
{
    std::vector<Button> temp;
    Titlebar::Dropdown proto = { false, title, temp, (int)Titlebar::dropdowns.size() };
    Titlebar::dropdowns.push_back(proto);
    return proto;
}

Titlebar::Button Titlebar::addButton(Titlebar::Dropdown dd, std::string text, u_int16_t callId)
{
    Titlebar::Button btn = { text, callId };
    Titlebar::dropdowns[dd.id].buttons.push_back(btn);
    return btn;
}

int Titlebar::pollEvent()
{
    if (Titlebar::eventQueue.size() == 0) return -1;
    else
    {
        int proto = Titlebar::eventQueue[0];
        Titlebar::eventQueue.erase(Titlebar::eventQueue.begin());
        return proto;
    }
}

void Titlebar::reset()
{
    Titlebar::dropdowns.clear();
}