#ifndef BALL_H
#define BALL_H

#include "Rectangle.h" 
#include "FileOperation.h"

class Ball
{
public:

	sf::CircleShape shape;
	sf::Vector2f velocity{ -dat.ballVelocity, -dat.ballVelocity };

	Ball(unsigned int mX, unsigned int mY)
	{
		shape.setPosition(mX / 2.f, mY / 2.f);
		shape.setRadius(dat.ballRadius);
		shape.setFillColor(sf::Color::Red);
		shape.setOrigin(dat.ballRadius, dat.ballRadius);
	}

	bool update(int windowWidth, int windowHeight)
	{
		shape.move(velocity);

		if (left() < 0)
			velocity.x = dat.ballVelocity;
		if (right() > windowWidth)
			velocity.x = -dat.ballVelocity;

		if (top() < 0)
			velocity.y = dat.ballVelocity;
		if (bottom() > windowHeight)
			return false;
			//velocity.y = -ballVelocity;
		return true;
	}

	float getX() const { return shape.getPosition().x; }
	float getY() const { return shape.getPosition().y; }
	float left() const { return getX() - shape.getRadius(); }
	float right() const { return getX() + shape.getRadius(); }
	float top() const { return getY() - shape.getRadius(); }
	float bottom() const { return getY() + shape.getRadius(); }

};

#endif /* BALL_H */