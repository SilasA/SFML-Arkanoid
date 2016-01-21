#include "stdafx.h"
#include "MainMenu.h"

#include <SFML\Graphics.hpp>
#include <string>
#include <array>


MainMenu::MainMenu()
{
	buttonArray[0] = this->playButton = new Button(100, "Play_Button.png");
	buttonArray[1] = this->exitButton = new Button(300, "Exit_Button.png");

	this->buttonArrayLength = sizeof(buttonArray) / sizeof(buttonArray[0]);

	buttonArray[0]->select();
}


void MainMenu::changeSelected(int change)
{
	if (currentRank + change < 0 || currentRank + change > 2) return;

	this->currentRank += change;

	for (int b = 0; b < buttonArrayLength; b++)
		if (buttonArray[b]->isSelected())
			buttonArray[b]->select();

	buttonArray[currentRank]->select();
}


int MainMenu::Display()
{
	while (menuWindow.isOpen())
	{
		sf::Event event;
		while (menuWindow.pollEvent(event))
		{
			// Close
			if (event.type == sf::Event::Closed)
				menuWindow.close();

			// Selection
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				if (playButton->isSelected())
				{
					menuWindow.close();
					return 0;
				}
				if (exitButton->isSelected())
				{
					menuWindow.close();
					return 1;
				}
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					changeSelected(-1);
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					changeSelected(1);
			}
		}

		menuWindow.clear();

		menuWindow.draw(playButton->button);
		menuWindow.draw(exitButton->button);

		menuWindow.display();

	}
	return 0;
}