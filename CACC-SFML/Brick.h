#ifndef BRICK_H
#define BRICK_H

#include "Rectangle.h"
#include "GameConfig.h"

class Brick : public Rectangle, public GameConfig
{
public:
	// If the brickis destroyed yet
	bool destroyed{ false };

	// Sets the Size, Color, Position, and its Origin.
	// Param mX: X position.
	// Param mY: Y position.
	Brick(float mX, float mY);

};

#endif /* BRICK_H */