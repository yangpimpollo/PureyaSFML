#include "game_init.h"

game_init::game_init()
{
}

game_init::~game_init()
{
}

void game_init::start()
{
    do {
        init();
        cicles();
    } while (contex->resetRequest);
	
	std::cout << "end of cycle";
}

void game_init::stop()
{
}

void game_init::init()
{
	sf::Image icon, cursorImg;
    sf::Cursor cursor;
	icon.loadFromFile("res/icon.png");
    cursorImg.loadFromFile("res/cursor.png");
    cursor.loadFromPixels(cursorImg.getPixelsPtr(), sf::Vector2u(20, 20), sf::Vector2u(0, 0));
    
	this->contex = new Context();
    this->window = new sf::RenderWindow(sf::VideoMode(contex->WIDTH, contex->HEIGHT), TITLE, contex->winStyle);
	this->window->setIcon(64, 64, icon.getPixelsPtr());
	this->window->setFramerateLimit(contex->frameLimit);
	this->window->setVerticalSyncEnabled(contex->verticalSync);
    this->window->setMouseCursor(cursor);
    //this->window->setMouseCursorGrabbed(true);
    //this->window->setPosition(sf::Vector2i(0, 500));
    
    
    this->view = new sf::View(sf::Vector2f(480.f, 240.f), sf::Vector2f(contex->realWidth, contex->realHeight));
    // View(center,size) center of the original draw canvas(960*480)


    this->debug = new debug_mode();
    this->stateMachine = new StateMachine();
    
    this->contex->setContextCanvas(this->window);
}

void game_init::cicles()
{
    sf::Time time_elapsed = sf::microseconds(0);
    fps = 0;
    while (this->window->isOpen())
    {
        sf::Clock clock;
        sf::Event event;
        this->contex->setCurrentEvent(&event);
        while (this->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                this->window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M)) {
                this->window->close();
                contex->setResetRequest(true);
            }

            
            if (event.type == sf::Event::MouseButtonReleased) {
                std::cout << " ---click-click---" << std::endl;
                std::cout << contex->getMousePosition().x << std::endl;
                std::cout << contex->getMousePosition().y << std::endl;
                
            }

        }
        update();
        render();
        fps++;
        time_elapsed += clock.restart();
        if (time_elapsed > sf::microseconds(1000000)) {
            debug->set_fps(fps);
            fps = 0;
            time_elapsed = sf::microseconds(0);
        }
    }
}

void game_init::update()
{
    this->stateMachine->updateState(this->contex);
    this->debug->update(this->contex);
}

void game_init::render()
{
    this->window->clear(sf::Color::Black);
    this->window->setView(*view);

    this->stateMachine->renderState(this->window);
    this->debug->render(this->window);

    this->window->display();
}
