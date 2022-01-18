#include "states/StateMachine.h"

StateMachine::StateMachine()
{
	std::cout << "state machine init" << std::endl;
	this->stateList.push_back(&stateScre);
	this->stateList.push_back(&stateMenu);
	this->stateList.push_back(&stateSetg);
	this->stateList.push_back(&statePlay);
	setCurrentState(stateList[0]);

	back.loadFromFile("res/landscape.png");
	background.setSize(sf::Vector2f(960.0f, 480.0f));
	//background:sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
	background.setTexture(&back);
	//background.setFillColor(sf::Color::Cyan);
	background.setPosition(0.f, 0.f);
}

StateMachine::~StateMachine()
{
}

void StateMachine::updateState(Context* arg)
{
	if (!this->currentState->getActiveStatus()){
		setCurrentState(stateList[this->currentState->getTargetState()]);
		this->currentState->resetState(arg);
	}
	if (this->currentState->getStateIdentity() == 0) {
		arg->canvas->setMouseCursorVisible(false);
	}
	else {
		arg->canvas->setMouseCursorVisible(true);
	}
	
	this->currentState->updateState(arg);
}

void StateMachine::renderState(sf::RenderWindow* arg)
{
	arg->draw(background);
	this->currentState->renderState(arg);
}

void StateMachine::setCurrentState(StateBase* arg)
{
	this->currentState = arg;
	this->currentState->setActiveStatus(true);
	
}
