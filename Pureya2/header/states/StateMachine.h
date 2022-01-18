#pragma once
#ifndef _STATEMACHINE_H_
#define _STATEMACHINE_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "util/Context.h"
#include "states/StateBase.h"
#include "states/state_SCRE.h"
#include "states/state_MENU.h"
#include "states/state_SETG.h"
#include "states/state_PLAY.h"

class StateMachine
{
private:
	StateBase* currentState;
	std::vector<StateBase*> stateList;

	state_SCRE stateScre;
	state_MENU stateMenu;
	state_SETG stateSetg;
	state_PLAY statePlay;

	sf::Texture back;
	sf::RectangleShape background;

public:
	StateMachine();
	~StateMachine();
	void updateState(Context* arg);
	void renderState(sf::RenderWindow* arg);
	void setCurrentState(StateBase* arg);

};

#endif