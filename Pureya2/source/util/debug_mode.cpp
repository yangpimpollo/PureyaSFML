#include "util/debug_mode.h"

debug_mode::debug_mode()
{
    font.loadFromFile("res/Mamelon.otf");
    fps_txt.setFont(font);
    fps_txt.setCharacterSize(18);
    fps_txt.setFillColor(sf::Color::Red);
    fps_txt.setPosition(30.f, 20.f);
}

debug_mode::~debug_mode()
{
}

void debug_mode::update(Context* arg)
{
    this->debug = arg->debug;
}

void debug_mode::render(sf::RenderWindow* arg)
{
    if(debug)
        arg->draw(this->fps_txt);
}

void debug_mode::set_fps(int arg)
{
    this->fps = arg;
    std::string str = std::to_string(fps);
    this->fps_txt.setString("fps: " + str);
}
