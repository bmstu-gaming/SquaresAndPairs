#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <fstream>

/*
 *	Start point
 */
int main() {


	sf::RenderWindow window;
	window.create(sf::VideoMode(1280, 720), "Game", sf::Style::Default);
	//	change the position of the window (relatively to the desktop)
	window.setPosition(sf::Vector2i(500, 50));
	/*	Doesn't work
	//	vertical synchronization enable
	*/
	window.setVerticalSyncEnabled(true);
	
	//	given framerate
	//window.setFramerateLimit(300);
	/*
	sf::CircleShape shape(100.f, 300);
	shape.setFillColor(sf::Color::Green);
	*/

	// Load font
	sf::Font font;
	if (!font.loadFromFile("assets/Consolas.ttf")) {
		std::cerr << "Font load error" << std::endl;
	}

	// Add text for FPS
	sf::Text fpsText;
	fpsText.setFont(font);
	fpsText.setCharacterSize(24);
	fpsText.setFillColor(sf::Color::White);

	// Add square
	sf::RectangleShape square(sf::Vector2f(50, 50));
	square.setPosition(600, 300);
	square.setFillColor(sf::Color::Red);

	sf::Clock clock;

	//	run the program as long as the window is open
	while ( window.isOpen() ) {

		//	check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;

		while ( window.pollEvent(event) ) {

			//	"close requested" event: we close the window
			if ( event.type == sf::Event::Closed ) {
				window.close();
			}
			//	The Resized event
			if ( event.type == sf::Event::Resized ) {
				std::cout << "new width: "	<< event.size.width		<< std::endl;
				std::cout << "new height: " << event.size.height	<< std::endl;

				window.setSize(sf::Vector2u(event.size.width, event.size.height));
			}
			//	LostFocus events
			if ( event.type == sf::Event::LostFocus ) {
				
			}
			//	GainedFocus events
			if ( event.type == sf::Event::GainedFocus ) {
				
			}
			//	The TextEntered event
			if ( event.type == sf::Event::TextEntered ) {
				if ( event.text.unicode < 128 ) {
					std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
				}
			}
			//	The KeyPressed and KeyReleased events
			if ( event.type == sf::Event::KeyPressed ) {
				if ( event.key.code == sf::Keyboard::Escape ) {
					std::cout << "the escape key was pressed" << std::endl;
					window.close();
				}
			}
			//	The MouseButtonPressed and MouseButtonReleased events
			if ( event.type == sf::Event::MouseButtonPressed ) {
				if ( event.mouseButton.button == sf::Mouse::Left ) {
					std::cout << "the Left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
				if (event.mouseButton.button == sf::Mouse::Right) {
					std::cout << "the Right button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
				if ( event.mouseButton.button == sf::Mouse::Middle ) {
					std::cout << "the Middle button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
				if ( event.mouseButton.button == sf::Mouse::XButton1 ) {
					std::cout << "the Extra 1 button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
				if ( event.mouseButton.button == sf::Mouse::XButton2 ) {
					std::cout << "the Extra 2 button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
			}
			//	The MouseMoved event
			if ( event.type == sf::Event::MouseMoved ) {
				std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
				std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
			}
			//	The MouseWheelScrolled event
			if ( event.type == sf::Event::MouseWheelScrolled ) {
				if ( event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel ) {
					std::cout << "wheel type: vertical" << std::endl;
				}
				else if ( event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel ) {
					std::cout << "wheel type: horizontal" << std::endl;
				}
				else {
					std::cout << "wheel type: unknown" << std::endl;
					std::cout << "wheel movement: "	<< event.mouseWheelScroll.delta << std::endl;
					std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
					std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
				}
			}
			//	The MouseEntered and MouseLeft event
			if ( event.type == sf::Event::MouseEntered ) {
				std::cout << "the mouse cursor has entered the window" << std::endl;
			}
			if ( event.type == sf::Event::MouseLeft ) {
				std::cout << "the mouse cursor has left the window" << std::endl;
			}




		}

		sf::Time elapsed = clock.restart();
		fpsText.setString(std::to_string(1.f / elapsed.asSeconds()));


		window.clear(sf::Color::Black);

		window.draw(square);
		window.draw(fpsText);

		window.display();

	}
	return 0;
}