#pragma once
#ifndef _STATE_SETG_H_
#define _STATE_SETG_H_

#include "states/StateBase.h"
#include "tools/Button.h"
#include "tools/Label.h"

class state_SETG : public StateBase
{
private:
	bool activeStatus = false;
	int targetState;
	Button saveBtn;
	Button backBtn;
	Label label1;
	Label label2;
	Label label3;
	Label label4; 
	Label label5;

	//-------
	sf::String A1 = L"confirm";
	sf::String A2 = L"確定";
	sf::String* P0 = &A1;
	//-------

	int Li[5] = { 0,0,0,0,0 };

	sf::String L1[2] = { "960 x 480", "1280 x 720" };
	sf::String L2[3] = { "none", "close", "fullscreen" };
	sf::String L3[2] = { "debug: false", "debug: true" };
	sf::String L4[2] = { "vsync: false", "vsync: true" };
	sf::String L5[2] = { "english", L"繁體中文" };


public:
	state_SETG();
	~state_SETG();
	void updateState(Context* arg);
	void renderState(sf::RenderWindow* arg);
	void changeState(int arg);
	void resetState(Context* arg);
	void setActiveStatus(bool arg);
	bool getActiveStatus();
	int getTargetState();
	int getStateIdentity();
	void action(Context* arg);
};

#endif
