#pragma once
#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "util/Context.h"

class Button
{
private:
	bool state = false;
	bool buttonEvent = false;
	float x, y, width, height;
	float txt_width;
	sf::Font font;
	sf::Text btnText;
	sf::Color color;
	sf::RectangleShape shape;
	sf::Vector2i mouse;
	bool mouseInButton;

public:
	//aButton(const sf::String arg);
	Button();
	~Button();

	void setBounds(float x, float y, float width, float height, const sf::String arg);
	void setColor(sf::Color color);
	void update(Context* arg);
	void draw(sf::RenderTarget& arg);
	bool getEvent();

};

#endif
