#include "states/state_PLAY.h"

state_PLAY::state_PLAY()
{
}

state_PLAY::~state_PLAY()
{
}

void state_PLAY::updateState(Context* arg)
{
}

void state_PLAY::renderState(sf::RenderWindow* arg)
{
}

void state_PLAY::changeState(int arg)
{
	this->targetState = arg;
	this->activeStatus = false;
}

void state_PLAY::resetState(Context* arg)
{
}

void state_PLAY::setActiveStatus(bool arg)
{
	this->activeStatus = arg;
}

bool state_PLAY::getActiveStatus()
{
	return activeStatus;
}

int state_PLAY::getTargetState()
{
	return targetState;
}

int state_PLAY::getStateIdentity()
{
	return 3;
}
