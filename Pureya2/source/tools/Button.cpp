#include "tools/Button.h"

Button::Button()
{

}

Button::~Button()
{
}

void Button::setBounds(float x, float y, float width, float height, const sf::String arg)
{
	sf::String MM = "開始 PLAY";
	std::string LL = "開始 PLAY";
	std::wstring NN; NN.assign(LL.begin(), LL.end());
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->btnText.setString(NN);

	shape.setSize(sf::Vector2f(width, height));
	shape.setPosition(x, y);

	//mouse = sf::Vector2i(0, 0);


	font.loadFromFile("res/Mamelon.otf");
	btnText.setFont(font);
	btnText.setCharacterSize(height - 8);
	btnText.setFillColor(sf::Color::White);
	txt_width = btnText.getLocalBounds().width;
	btnText.setPosition(x + ((width - txt_width) / 2), y);

}

void Button::setColor(sf::Color color)
{
	this->color = color;
	shape.setFillColor(color);
}

void Button::update(Context* arg)
{
	buttonEvent = false;
	//std::cout << "buton update" << std::endl;
	mouse = arg->getMousePosition();
	mouseInButton = mouse.x >= x &&
		mouse.x <= x + width &&
		mouse.y >= y &&
		mouse.y <= y + height;
	/*if (sf::Event::MouseButtonReleased) {
		if (mouseInButton) {
			std::cout << "CLICK" << std::endl;
		}
	}*/
	
	if (mouseInButton) {
		shape.setFillColor(sf::Color(6, 68, 212, 255));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			shape.setFillColor(color);
			state = true;
		}
		else {
			if (state == true && arg->event->type == sf::Event::MouseButtonReleased) {
				buttonEvent = true;
				std::cout << "CLICK" << std::endl;
				//buttonEvent = false;
			}
			state = false;
		}
		

		
	}
	else {
		shape.setFillColor(color);
		state = false;
	}
}

void Button::draw(sf::RenderTarget& arg)
{
	arg.draw(shape);
	arg.draw(btnText);
}

bool Button::getEvent()
{
	return buttonEvent;
}
