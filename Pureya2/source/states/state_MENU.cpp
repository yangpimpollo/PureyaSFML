#include "states/state_MENU.h"

state_MENU::state_MENU()
{
	startBtn.setBounds(355.f, 180.f, 250.f, 50.f, L"開始 PLAY");
	startBtn.setColor(sf::Color(162, 180, 222, 220));
	
	settgBtn.setBounds(355.f, 250.f, 250.f, 50.f, "OPTIONS");
	settgBtn.setColor(sf::Color(162, 180, 222, 220));
	
	closeBtn.setBounds(830.f, 430.f, 80.f, 20.f, "Exit");
	closeBtn.setColor(sf::Color(162, 180, 222, 180));
}

state_MENU::~state_MENU()
{
}

void state_MENU::updateState(Context* arg)
{
	startBtn.update(arg);
	settgBtn.update(arg);
	closeBtn.update(arg);
	action(arg);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B))
		std::cout << "menu AAAA" << std::endl;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X))
		//std::cout << "BBBBBBBB" << std::endl;
		//changeState(0);
}

void state_MENU::renderState(sf::RenderWindow* arg)
{
	//std::cout << "menu STATE render" << std::endl;
	startBtn.draw(*arg);
	settgBtn.draw(*arg);
	closeBtn.draw(*arg);
}

void state_MENU::changeState(int arg)
{
	this->targetState = arg;
	this->activeStatus = false;
}

void state_MENU::resetState(Context* arg)
{
}

void state_MENU::setActiveStatus(bool arg)
{
	this->activeStatus = arg;
}

bool state_MENU::getActiveStatus()
{
	return activeStatus;
}

int state_MENU::getTargetState()
{
	return targetState;
}

int state_MENU::getStateIdentity()
{
	return 1;
}

void state_MENU::action(Context* arg)
{
	if (settgBtn.getEvent()) changeState(2);
	if (startBtn.getEvent()) changeState(3);
	if (closeBtn.getEvent()) arg->canvas->close();
}
