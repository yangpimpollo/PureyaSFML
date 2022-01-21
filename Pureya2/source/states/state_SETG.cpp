#include "states/state_SETG.h"

state_SETG::state_SETG()
{
	saveBtn.setBounds(830.f, 400.f, 80.f, 20.f, *P0);
	saveBtn.setColor(sf::Color(162, 180, 222, 180));
	backBtn.setBounds(830.f, 430.f, 80.f, 20.f, "cancel");
	backBtn.setColor(sf::Color(162, 180, 222, 180));

	label1.setValues(300.f, 100.f, 40, L1[Li[0]]);
	label2.setValues(300.f, 150.f, 40, L2[Li[1]]);
	label3.setValues(300.f, 200.f, 40, L3[Li[2]]);
	label4.setValues(300.f, 250.f, 40, L4[Li[3]]);
	label5.setValues(300.f, 310.f, 30, L5[Li[4]]);

	
	
	
}

state_SETG::~state_SETG()
{
}

void state_SETG::updateState(Context* arg)
{
	saveBtn.update(arg);
	backBtn.update(arg);
	label1.update(arg);
	label2.update(arg);
	label3.update(arg);
	label4.update(arg);
	label5.update(arg);
	action(arg);
}

void state_SETG::renderState(sf::RenderWindow* arg)
{
	saveBtn.draw(*arg);
	backBtn.draw(*arg);
	label1.draw(*arg);
	label2.draw(*arg);
	label3.draw(*arg);
	label4.draw(*arg);
	label5.draw(*arg);
}

void state_SETG::changeState(int arg)
{
	this->targetState = arg;
	this->activeStatus = false;
}

void state_SETG::resetState(Context* arg)
{
	Li[0] = (arg->HEIGHT<500)? 0 : 1;
	Li[1] = (arg->winStyle) / 4;
	Li[2] = arg->debug;
	Li[3] = arg->verticalSync;
	Li[4] = arg->language;


	label1.setString(L1[Li[0]]);
	label2.setString(L2[Li[1]]);
	label3.setString(L3[Li[2]]);
	label4.setString(L4[Li[3]]);
	label5.setString(L5[Li[4]]);
}

void state_SETG::setActiveStatus(bool arg)
{
	this->activeStatus = arg;
}

bool state_SETG::getActiveStatus()
{
	return activeStatus;
}

int state_SETG::getTargetState()
{
	return targetState;
}

int state_SETG::getStateIdentity()
{
	return 2;
}

void state_SETG::action(Context* arg)
{
	if (label1.getClickEvent()) {
		Li[0] = (Li[0] > 0)? 0 : Li[0]+=1;
		label1.setString(L1[Li[0]]);
	}
		

	if (label2.getClickEvent()) {
		Li[1] = (Li[1] == 2) ? 0 : Li[1]+=1;
		label2.setString(L2[Li[1]]);
	}

	if (label3.getClickEvent()) {
		Li[2] = (Li[2] == 1) ? 0 : Li[2]+= 1;
		label3.setString(L3[Li[2]]);
		arg->debug = Li[2];
	}
		
	if (label4.getClickEvent()) {
		Li[3] = (Li[3] == 1) ? 0 : Li[3]+=1;
		label4.setString(L4[Li[3]]);
		arg->canvas->setVerticalSyncEnabled(Li[3]);
	}
		
	if (label5.getClickEvent()) {
		Li[4] = (Li[4] == 1) ? 0 : Li[4]+=1;
		label5.setString(L5[Li[4]]);
	}
		
	if (backBtn.getEvent()) {
		arg->loadSettings();
		arg->canvas->setVerticalSyncEnabled(arg->verticalSync);
		changeState(1);
	}
	if (saveBtn.getEvent()) {
		int newSet[7];

		newSet[0] = 960;// (Li[0] == 0) ? 960 : 1280;
		newSet[1] = 480;// (Li[0] == 0) ? 480 : 720;
		newSet[2] = Li[1]*4;
		newSet[3] = 0;
		newSet[4] = Li[3];
		newSet[5] = Li[4];
		newSet[6] = Li[2];

		arg->saveSettings(newSet);
		changeState(1);
		//arg->setResetRequest(true);
		//arg->canvas->close();
	}

}
