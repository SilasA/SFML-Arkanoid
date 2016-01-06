#ifndef BUTTON_H
#define BUTTON_H

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

#include "Rectangle.h"

const unsigned int menuWinHeight{ 600 }, menuWinWidth{ 800 };

class Button : public Rectangle
{

private:

	sf::Texture buttonImage;
	
	int spriteCoor;

	void update() { button.setTextureRect(sf::IntRect(0, spriteCoor, 400, 100)); }

public:

	sf::Sprite button;

	enum ButtonState { SELECTED, IDLE };
	ButtonState state = ButtonState::IDLE;

	int rank;

	Button()
	{
	}

	Button(float yPos, const std::string &dir, int rank)
	{
		this->rank = rank;

		if (buttonImage.loadFromFile(dir))
			std::cout << "Success." << std::endl;
		else
			std::cout << "Unable to find file." << std::endl;

		button.setTexture(buttonImage);
		button.setTextureRect(sf::IntRect(0, spriteCoor, 400, 100));

		button.setPosition((menuWinWidth / 2.f) - (),)
	}

	void select()
	{
		switch (spriteCoor)
		{
		case 0:
			spriteCoor = 105;
			state = ButtonState::SELECTED;
			break;
		case 105:
			spriteCoor = 0;
			state = ButtonState::IDLE;
			break;
		default:
			break;
		}

		update();
	}

};


#endif /* BUTTON_H */