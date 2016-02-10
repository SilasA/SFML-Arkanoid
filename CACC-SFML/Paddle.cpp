#include "Paddle.h"


Paddle::Paddle(unsigned int mX, unsigned int mY)
{
	shape.setPosition(mX, mY);
	shape.setSize({ paddleWidth, paddleHeight });
	shape.setFillColor(sf::Color::Red);
	shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
}


void Paddle::update()
{
	// Position
	shape.move(velocity);

	// Direction Change
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0)
		velocity.x = -paddleVelocity;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < windowWidth)
		velocity.x = paddleVelocity;
	else
		velocity.x = 0;
}