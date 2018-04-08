// SFML C++ Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>

int main()
{
	//Create RenderWindow called window with 300px by 300 px with name "Hello World!" and default window style
	sf::RenderWindow window(sf::VideoMode{ 300, 300}, "Hello World!", sf::Style::Default);

	//Set framerate limit to 60
	window.setFramerateLimit(60);

	//Create event handling variable
	sf::Event event;

	//Main loop, check if window is open
	while(window.isOpen()) {

		//Check if any event occurs
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) //If event is close button, close the window
			{
				window.close();
			}
		}

		window.clear(sf::Color::White); //Clear window to white color
		//Any items to draw goes here


		window.display(); //Display window
	}

    return 0;
}

