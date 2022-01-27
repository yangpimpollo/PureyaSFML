#include "util/Context.h"

Context::Context()
{
    loadSettings();

}

Context::~Context(){}

void Context::setResetRequest(bool arg){ 
    loadSettings();
    this->resetRequest = arg; 
    this->canvas->close();
}
void Context::setContextCanvas(sf::RenderWindow* arg0){ this->canvas = arg0; }
void Context::setCurrentEvent(sf::Event* arg){ this->event = arg; }

void Context::loadSettings()
{
    // load settings
    std::string setDat;
    std::fstream settingFile;
    settingFile.open(set_path, std::ios::in | std::ios::out | std::ios::app);
    for (int i = 0; i < 7; i++) {
        getline(settingFile, setDat);
        std::string delim = ":";
        auto end = setDat.find(delim) + 1;
        settings[i] = std::stoi(setDat.substr(end, setDat.length() - end));
    }
    settingFile.close();
    // assigning settings
    this->WIDTH = settings[0];
    this->HEIGHT = settings[1];
    this->winStyle = settings[2];
    this->frameLimit = settings[3];
    this->verticalSync = settings[4];
    this->language = settings[5];
    this->debug = settings[6];

    float multiply1 = 1360.f / this->WIDTH;
    float multiply2 = (this->WIDTH <1000)? 1.33f : 1.f;
    viewSize.x = (this->winStyle != 8) ? this->WIDTH * multiply1 : sf::VideoMode::getDesktopMode().width * multiply2;
    viewSize.y = (this->winStyle != 8) ? this->HEIGHT * multiply1 : sf::VideoMode::getDesktopMode().height * multiply2;
}

sf::Vector2i Context::getMousePosition()
{
    sf::Vector2i pixelPos = sf::Mouse::getPosition(*this->canvas);

    int x = (int)this->canvas->mapPixelToCoords(pixelPos).x;
    int y = (int)this->canvas->mapPixelToCoords(pixelPos).y;
    return sf::Vector2i(x, y);
}