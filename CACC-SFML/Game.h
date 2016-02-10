//
//

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Game : public GameConfig
{

public:

	// Tests if 2 objects are intersecting
	// Param mA: 1st object
	// Param mB: 2nd object
	// Returns: If it is intersecting
	template <class T1, class T2>
	bool isIntersecting(T1& mA, T2& mB);

	// Tests if the paddle and the ball are intersecting using 
	// isIntersecting() and then completes the apropriate action
	// Param mPaddle: Paddle object
	// Param mBall: Ball object
	void testCollision(Paddle& mPaddle, Ball& mBall);

	// Tests if a brick and the ball are intersecting using 
	// isIntersecting() and then completes the apropriate action
	// Param mPaddle: A brick object
	// Param mBall: Ball object
	void testCollision(Brick& mBrick, Ball& mBall);

	// Creates objects and the game window and positions them.  
	// It also contains the game's main loop which maintaines it.
	void gameMain();

};

#endif /* GAME_H */