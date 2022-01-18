#include "states/state_SCRE.h"

state_SCRE::state_SCRE()
{


	back.loadFromFile("res/landscape.png");
	background.setSize(sf::Vector2f(960.0f, 480.0f));
	//background:sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
	background.setTexture(&back);
	//background.setFillColor(sf::Color::Cyan);
	background.setPosition(0.f, 0.f);


	sf::Color color(220, 20, 60, 200);

	bar.setPosition(50.f, 430.f);
	bar.setFillColor(color);

	std::cout << "init screen" << std::endl;

}

state_SCRE::~state_SCRE()
{
}

void state_SCRE::updateState(Context* arg)
{
	if (barW < 860.0f) {
		barW += 4.7f;
		bar.setSize(sf::Vector2f(barW, 5.0f));
	}
	else {
		changeState(1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B))
		std::cout << "screen BBBB" << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X))
		barW = 0.0f;
	//std::cout << "BBBBBBBB" << std::endl;

}

void state_SCRE::renderState(sf::RenderWindow* arg)
{
	//std::cout << "screen STATE render" << std::endl;
	arg->draw(background);
	arg->draw(bar);
}

void state_SCRE::changeState(int arg)
{
	this->targetState = arg;
	this->activeStatus = false;
}

void state_SCRE::resetState(Context* arg)
{
}

void state_SCRE::setActiveStatus(bool arg)
{
	this->activeStatus = arg;
}

bool state_SCRE::getActiveStatus()
{
	return activeStatus;
}

int state_SCRE::getTargetState()
{
	return targetState;
}

int state_SCRE::getStateIdentity()
{
	return 0;
}
