// SFML C++ Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MainMenu.h"
#include "Snake.h"
#include "Board.h"
#include "Food.h"
#include <ctime>
#include <SFML/Graphics.hpp>

using namespace std;

sf::Color background(154, 197, 3);

Clock myClock;
float timer = 0;
float delay = 0.1f; //Fake framerate

void checkInputs();

struct Directions { bool UP = 0; bool DOWN = 0; bool LEFT = 0; bool RIGHT = 1; };
Directions movementDirections{ 0,0,0,1 };

extern enum GameStates { MAIN_MENU, PLAYING, EXIT };
extern GameStates gameStates = MAIN_MENU;

int snakeSpeed = 1;
int snakeLength = 3;
int xPos = 1;
int yPos = 0;

int main()
{
	
	//Create RenderWindow called window with 300px by 300 px with name "Hello World!" and default window style
	sf::RenderWindow window(sf::VideoMode{ 842, 482 }, "Snake", sf::Style::Default);
	MainMenu mainMenu(842, 428, background);

	//Set framerate limit to 60
	window.setFramerateLimit(30);

	//Create event handling variable
	sf::Event event;
	while (gameStates == MAIN_MENU) {
		mainMenu.drawMainMenu(window);
		if (mainMenu.state == 0) gameStates = EXIT;
		if (mainMenu.state == 1) gameStates = PLAYING;		
	}
	while (gameStates == PLAYING) {
		Board board;
		Food food;
		food.createFood(window, board.mapStates);
		myClock.restart();

		//Main loop, check if window is open
		while (window.isOpen()) {

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



			if (timer >= delay) //Fake framerate
			{
				checkInputs(); //Check for keyboard inputs
				window.clear(background); //Clear window
				if (movementDirections.RIGHT == 1) {
					xPos += snakeSpeed;
					if (xPos > 41) xPos = 0;
				}
				if (movementDirections.LEFT == 1) {
					xPos -= snakeSpeed;
					if (xPos < 0) xPos = 41;
				}
				if (movementDirections.UP == 1) {
					yPos -= snakeSpeed;
					if (yPos < 0) yPos = 23;
				}
				if (movementDirections.DOWN == 1) {
					yPos += snakeSpeed;
					if (yPos > 23) yPos = 0;
				}
				if (xPos == food.xPos && yPos == food.yPos) {
					snakeLength += 1;
					food.createFood(window, board.mapStates);
				}
				if (board.mapStates[xPos][yPos] > 0) { snakeSpeed = 0; sleep(milliseconds(1500)); window.close(); return 0; }

				board.setMapState(xPos, yPos, snakeLength); //Set values to MapStates

				board.drawBoard(window, snakeLength); //Display board
				food.drawFood(window); //Display food

				timer = 0; //Resets the timer
				window.display(); //Display window
			}

		}
	}
	if (gameStates == EXIT) window.close();
    return 0;
}

void checkInputs() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && movementDirections.DOWN != true) { movementDirections.UP = 1; movementDirections.LEFT = 0; movementDirections.RIGHT = 0; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && movementDirections.RIGHT != true) { movementDirections.UP = 0; movementDirections.DOWN = 0; movementDirections.LEFT = 1; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && movementDirections.UP != true) { movementDirections.DOWN = 1; movementDirections.LEFT = 0; movementDirections.RIGHT = 0; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && movementDirections.LEFT != true) { movementDirections.UP = 0; movementDirections.DOWN = 0; movementDirections.RIGHT = 1; }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) { snakeSpeed = 0; }
	else snakeSpeed = 1;
}
