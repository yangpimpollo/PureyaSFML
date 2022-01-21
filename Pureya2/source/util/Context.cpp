#include "util/Context.h"

Context::Context()
{
    loadSettings();

}

Context::~Context()
{
}

void Context::setResetRequest(bool arg)
{
    this->resetRequest = arg;
}

void Context::setContextCanvas(sf::RenderWindow* arg0)
{
    this->canvas = arg0;
    //this->debugMode = arg1;
}

void Context::setCurrentEvent(sf::Event* arg)
{
    this->event = arg;
}

void Context::loadSettings()
{
    // load settings
    std::string setDat;
    std::fstream settingFile;
    settingFile.open(set_path, std::ios::in | std::ios::out | std::ios::app);
    for (int i = 0; i < 7; i++) {
        getline(settingFile, setDat);
        settings[i] = std::stoi(setDat);
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

    if (this->winStyle == 8) {
        this->realWidth = sf::VideoMode::getDesktopMode().width;
        this->realHeight = sf::VideoMode::getDesktopMode().height;
    }
    else {
        this->realWidth = this->WIDTH;
        this->realHeight = this->HEIGHT;
    }
}

void Context::saveSettings(int arg[])
{
    this->WIDTH = arg[0];
    this->HEIGHT = arg[1];
    this->winStyle = arg[2];
    this->frameLimit = arg[3];
    this->verticalSync = arg[4];
    this->language = arg[5];
    this->debug = arg[6];

    std::fstream settingFile;
    settingFile.open(set_path, std::ios::out | std::ios::trunc);
    settingFile << arg[0] << std::endl;
    settingFile << arg[1] << std::endl;
    settingFile << arg[2] << std::endl;
    settingFile << arg[3] << std::endl;
    settingFile << arg[4] << std::endl;
    settingFile << arg[5] << std::endl;
    settingFile << arg[6];

    settingFile.close();
}

sf::Vector2i Context::getMousePosition()
{
    int x = sf::Mouse::getPosition(*this->canvas).x - ((this->realWidth-960.f)/2);
    int y = sf::Mouse::getPosition(*this->canvas).y - ((this->realHeight-480.f)/2);
    return sf::Vector2i(x, y);
}
