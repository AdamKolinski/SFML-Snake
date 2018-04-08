// SFML C++ Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Snake.h"
#include <ctime>
#include <SFML/Graphics.hpp>

using namespace std;

sf::Color background(154, 197, 3);

Clock myClock;
float timer = 0;
float delay = 0.2f; //Fake framerate

void checkInputs();

struct Directions { bool UP = 0; bool DOWN = 0; bool LEFT = 0; bool RIGHT = 1; };
Directions movementDirections{ 0,0,0,1 };

int snakeSpeed = 1 * 20;
int xPos = 1 * 20;
int yPos = 0 * 10;

int main()
{
	
	//Create RenderWindow called window with 300px by 300 px with name "Hello World!" and default window style
	sf::RenderWindow window(sf::VideoMode{ 840, 480}, "Snake", sf::Style::Default);
	
	//Set framerate limit to 60
	window.setFramerateLimit(60);

	//Create event handling variable
	sf::Event event;

	myClock.restart();

	//Main loop, check if window is open
	while(window.isOpen()) {

		float time = myClock.getElapsedTime().asSeconds();
		myClock.restart();
		timer += time;

		

		//Check if any event occurs
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) //If event is close button, close the window
			{
				window.close();
			}
		}

		checkInputs();

		if (timer >= delay) //Fake framerate
		{
			window.clear(background);
			if (movementDirections.RIGHT == 1) {
				xPos += snakeSpeed;
			}
			if (movementDirections.LEFT == 1) {
				xPos -= snakeSpeed;
			}
			if (movementDirections.UP == 1) {
				yPos -= snakeSpeed;
			}
			if (movementDirections.DOWN == 1) {
				yPos += snakeSpeed;
			}
			Snake snake(xPos, yPos);
			snake.drawHead(window);
			timer = 0;
			window.display(); //Display window
		}
		

		
	}

    return 0;
}

void checkInputs() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && movementDirections.DOWN != true) { movementDirections.UP = 1; movementDirections.LEFT = 0; movementDirections.RIGHT = 0; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && movementDirections.RIGHT != true) { movementDirections.UP = 0; movementDirections.DOWN = 0; movementDirections.LEFT = 1; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && movementDirections.UP != true) { movementDirections.DOWN = 1; movementDirections.LEFT = 0; movementDirections.RIGHT = 0; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && movementDirections.LEFT != true) { movementDirections.UP = 0; movementDirections.DOWN = 0; movementDirections.RIGHT = 1; }
}
