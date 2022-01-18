#pragma once
#ifndef _DEBUG_MODE_H_
#define _DEBUG_MODE_H_

#include <SFML/Graphics.hpp>
#include "util/Context.h"

class debug_mode
{
	private:
		sf::Font font;
		sf::Text fps_txt;
		int fps;
		bool debug;
	public:
		debug_mode();
		~debug_mode();
		void update(Context* arg);
		void render(sf::RenderWindow* arg);
		void set_fps(int arg);
};

#endif