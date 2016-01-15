#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML\Graphics.hpp>
#include <string>

#include "Button.h"


class MainMenu
{

private:

	sf::RenderWindow menuWindow{ { menuWinWidth, menuWinHeight }, "Main Menu" };

	Button *playButton;
	Button *exitButton;

	int currentRank = 1;
	int buttonCount;



public:

	int Display();

	MainMenu();
	
};


#endif /* MAINMENU_H */