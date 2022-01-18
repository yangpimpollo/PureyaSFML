#include "states/StateMachine.h"

StateMachine::StateMachine()
{
	std::cout << "state machine init" << std::endl;
	this->stateList.push_back(&stateScre);
	this->stateList.push_back(&stateMenu);
	this->stateList.push_back(&stateSetg);
	this->stateList.push_back(&statePlay);
	setCurrentState(stateList[0]);
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
	this->currentState->renderState(arg);
}

void StateMachine::setCurrentState(StateBase* arg)
{
	this->currentState = arg;
	this->currentState->setActiveStatus(true);
	
}
