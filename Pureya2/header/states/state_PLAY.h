#pragma once
#ifndef _STATE_PLAY_H_
#define _STATE_PLAY_H_

#include "states/StateBase.h"

class state_PLAY : public StateBase
{
private:
	bool activeStatus = false;
	int targetState;
public:
	state_PLAY();
	~state_PLAY();
	void updateState(Context* arg);
	void renderState(sf::RenderWindow* arg);
	void changeState(int arg);
	void resetState(Context* arg);
	void setActiveStatus(bool arg);
	bool getActiveStatus();
	int getTargetState();
	int getStateIdentity();
};

#endif