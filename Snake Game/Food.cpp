#include "stdafx.h"
#include "Food.h"
#include <ctime>
#include <cstdlib>


Food::Food()
{
	this->shape.setOrigin(Vector2f(-2, -2));
	this->shape.setSize(Vector2f(18, 18));
	this->shape.setFillColor(sf::Color::Red);
}

void Food::createFood(RenderWindow & window, int mapStates[42][24])
{
	srand(time(NULL));
	while (true) {
		this->xPos = (std::rand() % 42);
		this->yPos = (std::rand() % 24);
		if (mapStates[this->xPos][this->yPos] == 0) { this->shape.setPosition(Vector2f(this->xPos * 20, this->yPos * 20)); window.draw(this->shape); break; }
	}
}

void Food::drawFood(RenderWindow & window)
{
	window.draw(this->shape);
}

void Food::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->shape, state);
}