#include "stdafx.h"
#include "MainMenu.h"

#include <SFML\Graphics.hpp>
#include <string>


MainMenu::MainMenu()
{

	this->playButton = new Button(100, "Play_Button.png", 1);
	this->exitButton = new Button(300, "Exit_Button.png", 2);
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

			// When Up is pressed
			else if (event.type == sf::Keyboard::Up)
			{
				if (this->currentRank - 1 == playButton->rank)
				{
					playButton->select();
					this->currentRank--;
				}
			}

			// When Down is pressed
			else if (event.type == sf::Keyboard::Down)
			{
				if (this->currentRank + 1 == exitButton->rank)
				{
					exitButton->select();
					this->currentRank++;
				}
			}	

			// Selection
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				if (playButton->state == Button::ButtonState::SELECTED)
				{
					menuWindow.close();
					return 0;
				}
				else if (exitButton->state == Button::ButtonState::SELECTED)
				{
					menuWindow.close();
					return 1;
				}
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				sf::Mouse::getPosition(this->menuWindow).x < playButton->button.getPosition().x + 400 &&
				sf::Mouse::getPosition(this->menuWindow).x > playButton->button.getPosition().x &&
				sf::Mouse::getPosition(this->menuWindow).y > playButton->button.getPosition().y &&
				sf::Mouse::getPosition(this->menuWindow).y < playButton->button.getPosition().y + 100)
			{
				playButton->select();
			}
		}

		menuWindow.clear();

		menuWindow.draw(playButton->button);
		menuWindow.draw(exitButton->button);

		menuWindow.display();

	}
	return 0;
}