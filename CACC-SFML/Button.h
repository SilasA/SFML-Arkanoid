#ifndef BUTTON_H
#define BUTTON_H

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

#include "Rectangle.h"

const unsigned int menuWinHeight{ 600 }, menuWinWidth{ 800 };//

class Button
{

private:

	sf::Texture buttonImage;
	
	int spriteCoor = 0;

	void update() { button.setTextureRect(sf::IntRect(0, spriteCoor, 400, 100)); }

	enum ButtonState { SELECTED, IDLE };
	ButtonState state = ButtonState::IDLE;

public:

	sf::Sprite button;

	bool isSelected();

	Button();

	Button(float yPos, const std::string &dir);

	void select();

};


#endif /* BUTTON_H */