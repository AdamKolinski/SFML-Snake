#include "stdafx.h"
#include "Board.h"


Board::Board()
{
	this->shape.setOrigin(Vector2f(-2, -2));
	this->shape.setSize(Vector2f(18, 18));
	
}


void Board::setMapState(int xPos, int yPos, int snakeLength)
{
	this->mapStates[xPos][yPos] = snakeLength;
}

void Board::drawBoard(RenderWindow & window, int snakeLength)
{
	for (int i = 0; i < 42; i++) {
		for (int j = 0; j < 24; j++) {
			if (this->mapStates[i][j] > 0) { 
				if (this->mapStates[i][j] == snakeLength) this->shape.setFillColor(sf::Color::Black); else
				this->shape.setFillColor(sf::Color(0, 0, 0, 150)); 
				mapStates[i][j] -= 1; 
				this->shape.setPosition(Vector2f(i * 20, j * 20)); 
			}
			else this->shape.setFillColor(sf::Color::Transparent);
			window.draw(this->shape);
		}
	}
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->shape, state);
}