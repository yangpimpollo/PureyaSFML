#pragma once
#ifndef _STATE_SCRE_H_
#define _STATE_SCRE_H_

#include "states/StateBase.h"


class state_SCRE : public StateBase
{
private:
	sf::RectangleShape background;
	sf::RectangleShape bar;
	sf::Texture back;
	bool activeStatus = false;
	int targetState;
	float barW = 0.0f;

public:
	state_SCRE();
	~state_SCRE();
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