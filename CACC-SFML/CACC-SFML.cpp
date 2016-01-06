// CACC-SFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MainMenu.h"
#include "Game.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>



int _tmain(int argc, _TCHAR* argv[])
{
	int startup;

	MainMenu mainmenu;
	startup = mainmenu.Display();

	if (startup == 0)
	{
		Game game;
		game.gameMain();
	}

	return 0;
}

