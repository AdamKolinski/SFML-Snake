#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class MainMenu : Drawable
{
public:
	MainMenu(int t_WIDTH, int t_HEIGHT, sf::Color t_bg_color);
	~MainMenu() = default;

	int width, height, state, activeButton;
	sf::Color bg_color;
	sf::Font font;
	sf::Text text1;
	sf::Text text2;
	sf::Event event;
	sf::CircleShape shape;

	void drawMainMenu(RenderWindow& window);
	void changeGameState(int state);

private:
	void draw(RenderTarget& target, RenderStates state) const override;
};

