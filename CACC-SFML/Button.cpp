#include <SFML/Graphics.hpp>

#include "stdafx.h"
#include "Button.h"


Button::Button()
{
}


Button::Button(float yPos, const std::string &dir, int rank)
{
	this->rank = rank;

	if (buttonImage.loadFromFile(dir))
		std::cout << "Success." << std::endl;
	else
		std::cout << "Unable to find file." << std::endl;

	button.setTextureRect(sf::IntRect(0, 0, 400, 100));
	button.setTexture(buttonImage);
	button.setPosition((menuWinWidth / 2.f) - (400 / 2.f), yPos);
}


void Button::select()S
{
	if (state == ButtonState::IDLE)
	{
		this->spriteCoor = 105;
		this->state = ButtonState::SELECTED;
	}
	else
	{
		this->spriteCoor = 0;
		this->state = ButtonState::IDLE;
	}

	update();
}