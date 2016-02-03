#ifndef BRICK_H
#define BRICK_H

#include "Rectangle.h"
#include "FileOperation.h"

class Brick : public Rectangle, public FileOperation
{
public:
	bool destroyed{ false };

	Brick(float mX, float mY)
	{
		shape.setPosition(mX, mY);
		shape.setSize({ blockWidth, blockHeight });
		shape.setFillColor(sf::Color::Yellow);
		shape.setOrigin(blockWidth / 2.f, blockHeight / 2.f);
	}
};

#endif /* BRICK_H */