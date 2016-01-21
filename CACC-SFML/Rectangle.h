//
//

#ifndef RECTANGLE_H
#define RECTANGLE_H


#include <SFML/Graphics.hpp>
#include <string>

#include "FileOperation.h"

/*
const float ballRadius{ 10.f }, ballVelocity{ 2.f };
const float paddleWidth{ 60.f }, paddleHeight{ 20.f }, paddleVelocity{ 5.f };
const float blockWidth{ 60.f }, blockHeight{ 20.f };
*/

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