#pragma once
#ifndef _STATEBASE_H_
#define _STATEBASE_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "util/Context.h"

class StateBase
{
public:
	virtual void updateState(Context* arg) = 0;
	virtual void renderState(sf::RenderWindow* arg) = 0;
	virtual void changeState(int arg) = 0;
	virtual void resetState(Context* arg) = 0;
	virtual void setActiveStatus(bool arg) = 0;
	virtual bool getActiveStatus() = 0;
	virtual int getTargetState() = 0;
	virtual int getStateIdentity() = 0;
};

#endif