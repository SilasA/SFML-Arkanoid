#ifndef PADDLE_H
#define PADDLE_H

#include "Rectangle.h"
#include "GameConfig.h"


class Paddle : public Rectangle, public GameConfig
{
public:

	// Current velocity of the paddle.
	sf::Vector2f velocity;

	// Sets the Size, Position, Color and Origin of the paddle.
	// Param mX: X position.
	// Param mY: Y position.
	Paddle(unsigned int mX, unsigned int mY);

	// Updates the paddles position and velocity.
	void update();

};

#endif /* PADDLE_H */ 