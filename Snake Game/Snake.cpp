#include "stdafx.h"
#include "Snake.h"


Snake::Snake(int t_xPos, int t_yPos)
{
	this->snakeHead.setOrigin(Vector2f(-2, -2));
	this->snakeHead.setSize(Vector2f(18, 18));
	this->snakeHead.setPosition(t_xPos, t_yPos);
	this->snakeHead.setFillColor(sf::Color::Black);
}


void Snake::drawHead(RenderWindow & window)
{
	window.draw(this->snakeHead);
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->snakeHead, state);
}