//#include "util/eventListener.h"
//
//eventListener::eventListener()
//{
//}
//
//eventListener::~eventListener()
//{
//}
//
//void eventListener::setCanvas(sf::RenderWindow* arg)
//{
//    this->canvas = arg;
//}
//
//void eventListener::listening(sf::Event event)
//{
//    if (event.type == sf::Event::Closed)
//        this->canvas->close();
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
//        this->canvas->close();
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M)) {
//        this->canvas->close();
//        //contex->setResetRequest(true);
//    }
//
//
//    if (event.type == sf::Event::MouseButtonReleased) {
//        std::cout << "CLICK" << std::endl;
//
//    }
//}
