#include "MainMenu.h"


#include <SFML\Graphics.hpp>
#include <string>



MainMenu::MainMenu()
{
	this->menuWindow = new sf::RenderWindow{ { menuWinWidth, menuWinHeight }, "Main Menu" };

	this->playButton = new Button(100, "Play_Button.png");
	this->exitButton = new Button(300, "Exit_Button.png");
}