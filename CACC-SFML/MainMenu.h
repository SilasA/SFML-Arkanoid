#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML\Graphics.hpp>
#include <string>
#include <array>

#include "Button.h"
#include "FileOperation.h"


class MainMenu : public FileOperation
{

private:

	sf::RenderWindow menuWindow{ { menuWinWidth, menuWinHeight }, "Main Menu" };

	Button *playButton;
	Button *exitButton;

	int currentRank = 0;
	int buttonCount;

	void changeSelected(int change);

	int buttonArrayLength;

public:

	int Display();

	Button *buttonArray[2];

	MainMenu();

	~MainMenu();
	
};


#endif /* MAINMENU_H */