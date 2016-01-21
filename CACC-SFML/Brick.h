#ifndef BRICK_H
#define BRICK_H

#include "Rectangle.h"
#include "FileOperation.h"

class Brick : public Rectangle
{
public:
	bool destroyed{ false };

	Brick(float mX, float mY)
	{
		shape.setPosition(mX, mY);
		shape.setSize({ dat.blockWidth, dat.blockHeight });
		shape.setFillColor(sf::Color::Yellow);
		shape.setOrigin(dat.blockWidth / 2.f, dat.blockHeight / 2.f);
	}
};

#endif /* BRICK_H */