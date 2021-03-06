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

int score;

enum GameStates { MAIN_MENU, PLAYING, EXIT };
GameStates gameStates = MAIN_MENU;

int snakeSpeed = 1;
int snakeLength = 1;
int xPos = 1;
int yPos = 0;

int main()
{

	//Create RenderWindow called window with 300px by 300 px with name "Hello World!" and default window style
	sf::RenderWindow window(sf::VideoMode{ 842, 482 }, "Snake", sf::Style::Default);
	MainMenu mainMenu(842, 428, background);

	Font font;
	if (!font.loadFromFile("arial.ttf")) printf("Cannot load font!");

	score = 0;
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(24);
	scoreText.setString("0");
	scoreText.setPosition(10, 10);
	scoreText.setFillColor(Color::Black);

	//Set framerate limit to 60
	window.setFramerateLimit(30);

	//Create event handling variable
	sf::Event event;
	while (true)
	{


		while (gameStates == MAIN_MENU) {
			mainMenu.drawMainMenu(window);
			if (mainMenu.state == 0) gameStates = EXIT;
			if (mainMenu.state == 1) { gameStates = PLAYING; window.setTitle("Snake | Game"); 
			int snakeSpeed = 0;
			int snakeLength = 1;
			int xPos = 1;
			int yPos = 0;
			}
		}
		while (gameStates == PLAYING) {
			Board board;
			Food food;
			food.createFood(window, board.mapStates);
			myClock.restart();
			score = 0;
			scoreText.setString("0");

			movementDirections.UP = 0; movementDirections.DOWN = 0; movementDirections.LEFT = 0; movementDirections.RIGHT = 1;

			//Main loop, check if window is open
			while (gameStates != EXIT) {

				float time = myClock.getElapsedTime().asSeconds();
				myClock.restart();
				timer += time;



				//Check if any event occurs
				while (window.pollEvent(event)) {
					if (event.type == sf::Event::Closed) //If event is close button, close the window
					{
						gameStates = EXIT;
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
						score += 1;
						food.createFood(window, board.mapStates);
						scoreText.setString(to_string(score));
					}
					if (board.mapStates[xPos][yPos] > 0) {
						cout << "No i dupa" << endl;
						snakeSpeed = 0;
						window.setTitle("Snake | End");
						sleep(seconds(1));

						Text text;
						text.setFont(font);
						text.setCharacterSize(42);
						text.setString("Game Over");
						text.setPosition((window.getSize().x / 2.0f) - text.getLocalBounds().width / 2.0f, (window.getSize().y / 2.0f) - text.getLocalBounds().height * 2.0f);
						text.setFillColor(Color::Black);
						window.draw(text);

						text.setString("Your score: " + to_string(score));
						text.setPosition((window.getSize().x / 2.0f) - text.getLocalBounds().width / 2.0f, (window.getSize().y / 2.0f) + text.getLocalBounds().height * 2.0f);
						window.draw(text);

						window.display();
						sleep(milliseconds(1500));

						gameStates = MAIN_MENU;
						
						mainMenu.state = 3;
						xPos = 1;
						yPos = 0;
						snakeSpeed = 1;
						snakeLength = 1;
						board.resetBoard();
						mainMenu.activeButton = 0;
						break;
					}

					board.setMapState(xPos, yPos, snakeLength); //Set values to MapStates

					board.drawBoard(window, snakeLength); //Display board
					food.drawFood(window); //Display food
					window.draw(scoreText);

					timer = 0; //Resets the timer
					window.display(); //Display window
				}

			}
		}
		if (gameStates == EXIT) {
			window.close();
			return 0;
		}
	}
}

void checkInputs() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && movementDirections.DOWN != true) { movementDirections.UP = 1; movementDirections.LEFT = 0; movementDirections.RIGHT = 0; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && movementDirections.RIGHT != true) { movementDirections.UP = 0; movementDirections.DOWN = 0; movementDirections.LEFT = 1; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && movementDirections.UP != true) { movementDirections.DOWN = 1; movementDirections.LEFT = 0; movementDirections.RIGHT = 0; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && movementDirections.LEFT != true) { movementDirections.UP = 0; movementDirections.DOWN = 0; movementDirections.RIGHT = 1; }
}
