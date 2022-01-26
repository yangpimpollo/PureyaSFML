#pragma once
#ifndef _GAME_INIT_H_
#define _GAME_INIT_H_

#define TITLE "Pureya v3"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "util/Context.h"
#include "util/debug_mode.h"
//#include "state/StateMachine.h"

class game_init
{
public:
	game_init();
	~game_init();
	void start();
	void stop();
private:
	int fps;
	Context* contex;
	debug_mode* debug;
	sf::RenderWindow* window;
	sf::View* view;

	
	/*StateMachine* stateMachine;*/

	void init();
	void cicles();
	void update();
	void render();

};

#endif
