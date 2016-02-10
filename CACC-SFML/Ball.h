#ifndef BALL_H
#define BALL_H

#include "Rectangle.h" 
#include "GameConfig.h"


class Ball : public GameConfig
{
public:
	
	// The circle that is the ball.
	sf::CircleShape shape;

	// X and Y Velocity of the ball.
	sf::Vector2f velocity{ -ballVelocity, -ballVelocity };

	// Sets the Position, Size, Color and Origin of the ball..
	// Param mX: 2x the desired X position.
	// Param mY: 2x the desired Y position.
	Ball(unsigned int mX, unsigned int mY);

	// Updates the balls Position and direction.
	bool update();

	// Returns the X position.
	float getX() const { return shape.getPosition().x; }

	// Returns the Y position.
	float getY() const { return shape.getPosition().y; }

	// Returns the Left side's position.
	float left() const { return getX() - shape.getRadius(); }

	// Returns the Right side's position.
	float right() const { return getX() + shape.getRadius(); }

	// Returns the Top side's position.
	float top() const { return getY() - shape.getRadius(); }

	// Returns the Bottom side's position.
	float bottom() const { return getY() + shape.getRadius(); }

};

#endif /* BALL_H */