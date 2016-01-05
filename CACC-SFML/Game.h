//
//

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "stdafx.h"

class Game
{
public:

	template <class T1, class T2>
	bool isIntersecting(T1& mA, T2& mB);

	void testCollision(Paddle& mPaddle, Ball& mBall);

	void testCollision(Brick& mBrick, Ball& mBall);

	void gameMain();

};

#endif /* GAME_H */