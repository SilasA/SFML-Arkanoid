#include <SFML/Graphics.hpp>

#include "stdafx.h"
#include "Button.h"


Button::Button()
{
	state = Button::ButtonState::IDLE;
}


Button::Button(float yPos, const std::string &dir)
{
	if (buttonImage.loadFromFile(dir))
		std::cout << "loaded:" << dir << std::endl;
	else
		std::cout << "Unable to find: " << dir << std::endl;

	button.setTextureRect(sf::IntRect(0, 0, 400, 100));
	button.setTexture(buttonImage);
	button.setPosition((menuWinWidth / 2.f) - (400 / 2.f), yPos);
	state = Button::ButtonState::IDLE;
}


bool Button::isSelected() { return this->state == Button::ButtonState::SELECTED; }


void Button::select()
{
	if (state == ButtonState::IDLE)
	{
		spriteCoor = 105;
		state = ButtonState::SELECTED;
	}
	else
	{
		spriteCoor = 0;
		state = ButtonState::IDLE;
	}

	update();
}