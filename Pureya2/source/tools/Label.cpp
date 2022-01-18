#include "tools/Label.h"

Label::Label()
{
}

Label::~Label()
{
}

void Label::update(Context* arg)
{
	clickEvent = false;
	mouse = arg->getMousePosition();
	mouseInLabel = mouse.x >= x &&
		mouse.x <= x + width &&
		mouse.y >= y &&
		mouse.y <= y + height;
	
	
	if (mouseInLabel) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			state = true;
		}
		else {
			if (state == true && arg->event->type == sf::Event::MouseButtonReleased) {
				clickEvent = true;
				//std::cout << "CLICK LABEL" << std::endl;
			}
			state = false;
		}
	}
	else {
		state = false;
	}
}

void Label::draw(sf::RenderTarget& arg)
{
	arg.draw(labelText);
}

void Label::setValues(float x, float y, int size, sf::String arg)
{
    this->x = x;
    this->y = y;
    font.loadFromFile("res/Mamelon.otf");
    labelText.setFont(font);
    labelText.setCharacterSize(size);
    labelText.setFillColor(sf::Color::White);
    labelText.setPosition(x, y);
    labelText.setString(arg);
    this->width = labelText.getLocalBounds().width;
    this->height = labelText.getLocalBounds().height;

}

void Label::setString(sf::String arg)
{
	labelText.setString(arg);
}

bool Label::getClickEvent()
{
    return clickEvent;
}
