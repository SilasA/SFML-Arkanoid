#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML\Graphics.hpp>
#include <string>
#include <array>

#include "Button.h"
#include "GameConfig.h"


class MainMenu : public GameConfig
{

private:

	// Menu Window.
	sf::RenderWindow menuWindow{ { menuWinWidth, menuWinHeight }, "Main Menu" };

	// Menu buttons (play button, exit button)
	Button *playButton;
	Button *exitButton;

	// Current index location of the selected button.
	int currentRank = 0;

	// Changes the selected button based on which button was pressed 
	// (Up & Down)
	// Param change: Amount and Direction(+ or -) the buttons were pushed.
	void changeSelected(int change);

	// Length of the button array.
	int buttonArrayLength;

public:

	// Main loop to maintain the menu window.
	// Returns: Code for what should be done upon closing.
	int Display();

	// Array of the main menu buttons.
	Button *buttonArray[2];

	// Creates the buttons and puts them into the array and selects the 
	// default (Play Button) button.
	MainMenu();

};


#endif /* MAINMENU_H */