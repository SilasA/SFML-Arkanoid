//
//

#ifndef RECTANGLE_H
#define RECTANGLE_H


#include <SFML/Graphics.hpp>
#include <string>


class Rectangle
{
public:

	// The shape that is the rectangle.
	sf::RectangleShape shape;

	// Rectangle's Color.
	sf::Color color;

	// Returns X position.
	float getX() const { return shape.getPosition().x; }

	// Returns Y position. 
	float getY() const { return shape.getPosition().y; }

	// Returns the Left side's position.
	float left() const { return getX() - shape.getSize().x / 2.f; }

	// Returns the Right side's position.
	float right() const { return getX() + shape.getSize().x / 2.f; }

	// Returns the Top side's position.
	float top() const { return getY() - shape.getSize().y / 2.f; }

	// Returns the Bottom side's position.
	float bottom() const { return getY() + shape.getSize().y / 2.f; }

};

#endif /* RECTANGLE_H */