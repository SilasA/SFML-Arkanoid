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
	sf::Sprite button;

	int spriteCoor;

	void update() { button.setTextureRect(sf::IntRect(0, spriteCoor, 400, 100)); }

public:

	Button(float yPos, const std::string &dir)
	{
		if (buttonImage.loadFromFile(dir))
			std::cout << "Success." << std::endl;
		else
			std::cout << "Unable to find file." << std::endl;

		button.setTexture(buttonImage);
		button.setTextureRect(sf::IntRect(0, spriteCoor, 400, 100));
	}

	void select()
	{
		switch (spriteCoor)
		{
		case 0:
			spriteCoor = 105;
			break;
		case 105:
			spriteCoor = 0;
			break;
		default:
			break;
		}

		update();
	}

};


#endif /* BUTTON_H */