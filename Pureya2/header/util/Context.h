#pragma once
#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#define set_path "settings/settings.wo"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

class Context
{
	public:
		Context();
		~Context();
		int WIDTH;
		int HEIGHT;
		float realWidth;
		float realHeight;
		int winStyle;
		int frameLimit;
		bool verticalSync;
		int language;
		bool debug;
		bool resetRequest = false;
		sf::RenderWindow* canvas;
		sf::Event* event;

		void setResetRequest(bool arg);
		void setContextCanvas(sf::RenderWindow* arg0);
		void setCurrentEvent(sf::Event* arg);
		void loadSettings();
		void saveSettings(int arg[]);
		sf::Vector2i getMousePosition();

	private:
		int settings[7];	
		
};



#endif