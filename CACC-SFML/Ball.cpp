#include "stdafx.h"
#include "Ball.h"


Ball::Ball(unsigned int mX, unsigned int mY)
{
	shape.setPosition(mX / 2.f, mY / 2.f);
	shape.setRadius(ballRadius);
	shape.setFillColor(sf::Color::Red);
	shape.setOrigin(ballRadius, ballRadius);
}


bool Ball::update()
{
	// Position
	shape.move(velocity);

	// Direction X
	if (left() < 0)
		velocity.x = ballVelocity;
	if (right() > windowWidth)
		velocity.x = -ballVelocity;
	// Y
	if (top() < 0)
		velocity.y = ballVelocity;
	if (bottom() > windowHeight)
		return false;
	//velocity.y = -ballVelocity;
	return true;
}