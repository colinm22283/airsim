#pragma once

#include <string>
#include <vector>

namespace Titlebar
{
    struct Button
    {
        std::string text;
        u_int16_t callId;
    };
    struct Dropdown
    {
        bool open;
        std::string name;
        std::vector<Button> buttons;
        int id;
    };

    extern bool enabled;

    extern std::vector<Dropdown> dropdowns;
    extern std::vector<int> eventQueue;

    void update();
    void mouseClick(int button);
    Titlebar::Dropdown addDropdown(std::string title);
    Titlebar::Button addButton(Titlebar::Dropdown dd, std::string text, u_int16_t callId);
    int pollEvent();
    void reset();
}