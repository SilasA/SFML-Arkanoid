#ifndef PADDLE_H
#define PADDLE_H

#include "Rectangle.h"
#include "FileOperation.h"

class Paddle : public Rectangle
{
public:

	sf::Vector2f velocity;

	Paddle(unsigned int mX, unsigned int mY)
	{
		shape.setPosition(mX, mY);
		shape.setSize({ dat.paddleWidth, dat.paddleHeight });
		shape.setFillColor(sf::Color::Red);
		shape.setOrigin(dat.paddleWidth / 2.f, dat.paddleHeight / 2.f);
	}

	void update(int windowWidth)
	{
		shape.move(velocity);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0)
			velocity.x = -dat.paddleVelocity;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < windowWidth)
			velocity.x = dat.paddleVelocity;
		else
			velocity.x = 0;
	}
};

#endif /* PADDLE_H */ 