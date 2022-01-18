#include "util/debug_mode.h"

debug_mode::debug_mode()
{
    font.loadFromFile("res/Mamelon.otf");
    fps_txt.setFont(font);
    fps_txt.setCharacterSize(18);
    fps_txt.setFillColor(sf::Color::Red);
    fps_txt.setPosition(30.f, 20.f);

    mouse_X.setFont(font);
    mouse_X.setCharacterSize(12);
    mouse_X.setFillColor(sf::Color::Red);
    mouse_X.setPosition(30.f, 45.f);

    mouse_Y.setFont(font);
    mouse_Y.setCharacterSize(12);
    mouse_Y.setFillColor(sf::Color::Red);
    mouse_Y.setPosition(30.f, 60.f);
}

debug_mode::~debug_mode()
{
}

void debug_mode::update(Context* arg)
{
    this->debug = arg->debug;
    std::string x = std::to_string(arg->getMousePosition().x);
    std::string y = std::to_string(arg->getMousePosition().y);
    this->mouse_X.setString("x: " + x);
    this->mouse_Y.setString("y: " + y);
}

void debug_mode::render(sf::RenderWindow* arg)
{
    if (debug) {
        arg->draw(this->fps_txt);
        arg->draw(this->mouse_X);
        arg->draw(this->mouse_Y);
    }
}

void debug_mode::set_fps(int arg)
{
    this->fps = arg;
    std::string str = std::to_string(fps);
    this->fps_txt.setString("fps: " + str);
}
