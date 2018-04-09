#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
class Food : sf::Drawable
{
public:
	Food();
	~Food() = default;

	int xPos, yPos;

	void createFood(RenderWindow& window, int mapStates[42][24]);
	void drawFood(RenderWindow& window);

	RectangleShape shape;

private:
	void draw(RenderTarget& target, RenderStates state) const override;
};

