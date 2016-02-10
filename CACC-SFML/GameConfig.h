#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <iostream>
#include <string>
#include <fstream>


// Stores config information for the game/application.
const class GameConfig
{
protected:

	// Config file variables 
	// Window dimensions
	unsigned int menuWinHeight{ 600 },
		menuWinWidth{ 800 },
		windowWidth{ 800 }, 
		windowHeight{ 600 };

	// Block count
	int countBlocksX{ 11 },
		countBlocksY{ 4 };

	// Object dimensions
	float ballRadius{ 10 },
		ballVelocity{ 2 },
		paddleWidth{ 60 },
		paddleHeight{ 20 },
		paddleVelocity{ 5 },
		blockWidth{ 60 }, 
		blockHeight{ 20 },
		ftStep{ 1 },
		ftSlice{ 1 };

};


#endif /* GAMECONFIG_H */