//
//

#ifndef RECTANGLE_H
#define RECTANGLE_H


#include <SFML/Graphics.hpp>
#include <string>

#include "FileOperation.h"


class Rectangle
{
public:

	sf::RectangleShape shape;
	sf::Color color;

	float getX() const { return shape.getPosition().x; }
	float getY() const { return shape.getPosition().y; }
	float left() const { return getX() - shape.getSize().x / 2.f; }
	float right() const { return getX() + shape.getSize().x / 2.f; }
	float top() const { return getY() - shape.getSize().y / 2.f; }
	float bottom() const { return getY() + shape.getSize().y / 2.f; }
};

#endif /* RECTANGLE_H */