#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Snake : sf::Drawable
{
public:
	Snake(int t_xPos, int t_yPos);
	~Snake() = default;
	sf::RectangleShape snakeHead;

	void drawHead(RenderWindow& window);

private:
	void draw(RenderTarget& target, RenderStates state) const override;
};

