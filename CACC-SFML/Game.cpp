//
//

#include "stdafx.h"
#include "Game.h"

#include <SFML/Graphics.hpp>
#include <string>

const unsigned int windowWidth{ 800 }, windowHeight{ 600 };
const int countBlocksX{ 11 }, countBlocksY{ 4 };
const float ftStep{ 1.f }, ftSlice{ 1.f };


template <class T1, class T2>
bool Game::isIntersecting(T1& mA, T2& mB)
{
	return mA.right() >= mB.left() && mA.left() <= mB.right() &&
		   mA.bottom() > mB.top() && mA.top() <= mB.bottom();
}


void Game::testCollision(Paddle& mPaddle, Ball& mBall)
{
	if (!isIntersecting(mPaddle, mBall)) return;

	mBall.velocity.y = -ballVelocity;

	if (mPaddle.velocity.x == -paddleVelocity && mBall.velocity.x == ballVelocity)
		mBall.velocity.x = -ballVelocity;
	else if (mPaddle.velocity.x == paddleVelocity && mBall.velocity.x == -ballVelocity)
		mBall.velocity.x = ballVelocity;
}


void Game::testCollision(Brick& mBrick, Ball& mBall)
{
	if (!isIntersecting(mBrick, mBall)) return;
	mBrick.destroyed = true;

	float overLapLeft{ mBall.right() - mBrick.left() };
	float overLapRight{ mBrick.right() - mBall.left() };
	float overLapTop{ mBall.bottom() - mBrick.top() };
	float overLapBottom{ mBrick.bottom() - mBall.top() };

	bool ballFromLeft(abs(overLapLeft) < abs(overLapRight));
	bool ballFromTop(abs(overLapTop) < abs(overLapBottom));

	float minOverlapX{ ballFromLeft ? overLapLeft : overLapRight };
	float minOverlapY{ ballFromTop ? overLapTop : overLapBottom };

	if (abs(minOverlapX) < abs(minOverlapY))
		mBall.velocity.x = ballFromLeft ? -ballVelocity : ballVelocity;
	else
		mBall.velocity.y = ballFromTop ? -ballVelocity : ballVelocity;
}


void Game::gameMain()
{
	Ball ball{ windowWidth , windowHeight };
	Paddle paddle{ windowWidth, windowHeight};
	std::vector<Brick> bricks;

	for (int iX = 0; iX < countBlocksX; ++iX)
		for (int iY = 0; iY < countBlocksY; ++iY)
			bricks.emplace_back((iX + 1) * (blockWidth + 3) + 22, (iY + 2) * (blockHeight + 3));

	sf::RenderWindow window{ { windowWidth, windowHeight }, "Arkanoid Clone" };
	window.setFramerateLimit(60);

	while (true)
	{
		window.clear(sf::Color::Black);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) break;

		ball.update(windowWidth, windowHeight);
		paddle.update(windowWidth);
		testCollision(paddle, ball);

		for (auto& brick : bricks) testCollision(brick, ball);
		bricks.erase(remove_if(begin(bricks), end(bricks),
			[](const Brick& mBrick)
		{
			return mBrick.destroyed;
		}),
			end(bricks));

		window.draw(ball.shape);
		window.draw(paddle.shape);
		for (auto& brick : bricks) window.draw(brick.shape);
		window.display();
	}

	return;
}