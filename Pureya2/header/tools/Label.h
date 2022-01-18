#pragma once
#ifndef _LABEL_H_
#define _LABEL_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "util/Context.h"

class Label
{
	private:
		sf::Font font;
		sf::Text labelText;
		sf::Color color;
		sf::Vector2i mouse;
		float x, y, width, height;
		bool state = false;
		bool mouseInLabel;
		bool clickEvent = false;
	public:
		Label();
		~Label();
		void update(Context* arg);
		void draw(sf::RenderTarget& arg);
		void setValues(float x, float y, int size, sf::String arg);
		void setString(sf::String arg);
		bool getClickEvent();



};


#endif
