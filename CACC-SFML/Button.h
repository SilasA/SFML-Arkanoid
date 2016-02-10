#ifndef BUTTON_H
#define BUTTON_H

#include <SFML\Graphics.hpp>
#include <string>

#include "Rectangle.h"


class Button : public GameConfig
{

private:

	// Image used for the button sprite.
	sf::Texture buttonImage;
	
	// Changing coordinate to animate the sprite.
	int spriteCoor = 0;

	// Changes the sprite between the 2 image locations.
	void update() { button.setTextureRect(sf::IntRect(0, spriteCoor, 400, 100)); }

	// Current state of the button.
	enum ButtonState { SELECTED, IDLE };
	ButtonState state = ButtonState::IDLE;

public:

	// Button Sprite.
	sf::Sprite button;

	// Returns if the button is in the selected state.
	bool isSelected();

	// Default Constructor that sets the button's state.
	Button();

	// Sets the y posistion and the image for the spite upon
	// construction.
	// Param yPos: Y position of button.
	// Param dir: Directory of the image.
	Button(float yPos, const std::string &dir);

	// Changes the sprite and state.
	void select();

};


#endif /* BUTTON_H */