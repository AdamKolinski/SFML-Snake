#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
class Board : sf::Drawable
{
public:
	Board();
	~Board() = default;

	RectangleShape shape;
	int age;
	int mapStates[42][24];

	void setMapState(int xPos, int yPos, int snakeLength);
	void drawBoard(RenderWindow& window, int snakeLength);
	void resetBoard();

private:
	void draw(RenderTarget& target, RenderStates state) const override;
};

