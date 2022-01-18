#pragma once
#ifndef _STATE_MENU_H_
#define _STATE_MENU_H_

#include "states/StateBase.h"
#include "tools/Button.h"

class state_MENU : public StateBase
{
private:
	bool activeStatus = false;
	int targetState;
	Button startBtn;
	Button settgBtn;

public:
	state_MENU();
	~state_MENU();
	void updateState(Context* arg);
	void renderState(sf::RenderWindow* arg);
	void changeState(int arg);
	void resetState(Context* arg);
	void setActiveStatus(bool arg);
	bool getActiveStatus();
	int getTargetState();
	int getStateIdentity();
	void action();
};

#endif