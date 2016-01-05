#ifndef BALL_H
#define BALL_H

#include "Rectangle.h" 

class Ball
{
public:

	sf::CircleShape shape;
	sf::Vector2f velocity{ -ballVelocity, -ballVelocity };

	Ball(unsigned int mX, unsigned int mY)
	{
		shape.setPosition(mX / 2.f, mY / 2.f);
		shape.setRadius(ballRadius);
		shape.setFillColor(sf::Color::Red);
		shape.setOrigin(ballRadius, ballRadius);
	}

	void update(int windowWidth, int windowHeight)
	{
		shape.move(velocity);

		if (left() < 0)
			velocity.x = ballVelocity;
		else if (right() > windowWidth)
			velocity.x = -ballVelocity;

		if (top() < 0)
			velocity.y = ballVelocity;
		//else if (bottom() > windowHeight)
		//	velocity.y = -ballVelocity;
	}

	float getX() const { return shape.getPosition().x; }
	float getY() const { return shape.getPosition().y; }
	float left() const { return getX() - shape.getRadius(); }
	float right() const { return getX() + shape.getRadius(); }
	float top() const { return getY() - shape.getRadius(); }
	float bottom() const { return getY() + shape.getRadius(); }

};

#endif /* BALL_H */