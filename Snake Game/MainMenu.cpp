#include "stdafx.h"
#include "MainMenu.h"
#include <SFML\Graphics.hpp>

#include <iostream>

MainMenu::MainMenu(int t_WIDTH, int t_HEIGHT, sf::Color t_bg_color)
{
	this->width = t_WIDTH;
	this->height = t_HEIGHT;
	this->bg_color = t_bg_color;
	this->state = 3;
	this->activeButton = 0;

	this->shape.setRadius(6);
	this->shape.setFillColor(Color::Black);
	

	if (!this->font.loadFromFile("arial.ttf"))
	{
		printf("Cannot load font!");
	}

	this->text1.setFont(font);
	this->text1.setString("Play");
	this->text1.setCharacterSize(42);
	this->text1.setFillColor(Color::Black);
	this->text1.setPosition((width / 2.0f) - this->text1.getLocalBounds().width / 2.0f, (height / 2.0f) - this->text1.getLocalBounds().height * 2);

	this->text2.setFont(font);
	this->text2.setString("Exit");
	this->text2.setCharacterSize(42);
	this->text2.setFillColor(Color::Black);
	this->text2.setPosition((width / 2.0f) - this->text2.getLocalBounds().width / 2.0f, (height / 2.0f) + this->text2.getLocalBounds().height * 2);

	this->shape.setPosition((width / 2.0f) - this->text1.getLocalBounds().width + 10, (height / 2.0f) - this->text1.getLocalBounds().height * 1.5f);

}

void MainMenu::drawMainMenu(RenderWindow & window)
{
	window.setTitle("Snake | Main menu");
	window.clear(bg_color);
	
	window.draw(shape);
	window.draw(text1);
	window.draw(text2);

	window.display();

	while (window.pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) //If event is close button, close the window
		{
			changeGameState(0);
		}
		if (this->event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W)
		{
			this->activeButton += 1;
			if (this->activeButton > 1)
			{
				this->activeButton = 0;
			}
			if (this->activeButton == 0) { 
				this->shape.setPosition((width / 2.0f) - this->text1.getLocalBounds().width + 10, (height / 2.0f) - this->text1.getLocalBounds().height * 1.5f);
				//this->text1.setFillColor(Color::Red); this->text2.setFillColor(Color::Black); 
			}
			else if (this->activeButton == 1)
			{
				this->shape.setPosition((width / 2.0f) - this->text1.getLocalBounds().width + 10, (height / 2.0f) + this->text2.getLocalBounds().height * 2.6f);
				//this->text1.setFillColor(Color::Black); this->text2.setFillColor(Color::Red);
			}
		}
		if (this->event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S)
		{
			this->activeButton -= 1;
			if (this->activeButton < 0)
			{
				this->activeButton = 1;
			}
			if (this->activeButton == 0) {
				this->shape.setPosition((width / 2.0f) - this->text1.getLocalBounds().width + 10, (height / 2.0f) - this->text1.getLocalBounds().height * 1.5f);
				//this->text1.setFillColor(Color::Red); this->text2.setFillColor(Color::Black); 
			}
			else if (this->activeButton == 1)
			{
				this->shape.setPosition((width / 2.0f) - this->text1.getLocalBounds().width + 10, (height / 2.0f) + this->text2.getLocalBounds().height * 2.6f);
				//this->text1.setFillColor(Color::Black); this->text2.setFillColor(Color::Red);
			}
		}
		if (this->event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		{
			if (this->activeButton == 1) changeGameState(0);
			else if (this->activeButton == 0) changeGameState(1);
		}
	}
}

void MainMenu::changeGameState(int toState)
{
	this->state = toState;
}

void MainMenu::draw(RenderTarget& target, RenderStates state) const {
	
}