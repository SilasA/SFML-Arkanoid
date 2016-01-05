#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML\Graphics.hpp>
#include <string>

#include "Button.h"


class MainMenu
{
public:

	sf::RenderWindow *menuWindow;

	Button *playButton;
	Button *exitButton;

	MainMenu();

};


#endif /* MAINMENU_H */