/******************************************************************************
*
*	@file	main.cpp
*
*	@brief	This file contains the game logic
*
*	Group: BMSTU GaminG
*	Target Device: PC
*
******************************************************************************

Copyright (c) 2019, BMSTU GaminG Incorporated
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

*  Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.

*  Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

*  Neither the name of Texas Instruments Incorporated nor the names of
its contributors may be used to endorse or promote products derived
from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

******************************************************************************
Release Name: 
Release Date: 
*****************************************************************************/

/*********************************************************************
*	INCLUDES
*/
#include <stdio.h>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <thread>
#include <mutex>

/*********************************************************************
*	CLASSES
*/

/*********************************************************************
*	CONSTANTS
*/

/*********************************************************************
*	TYPEDEFS
*/

/*********************************************************************
* LOCAL FUNCTIONS
*/

/*****************************************************************
*	@fn		threadRenderingWindow
*
*	@brief	Render each frame in window
*	
*/
void threadRenderingWindow(sf::RenderWindow* window) {

	//	activate the window's context
	window->setActive(true);
	
	//	Load font
	sf::Font font;
	if (!font.loadFromFile("assets/Consolas.ttf")) {
		std::cerr << "Font load error" << std::endl;
	}

	sf::Clock clock;
	// the rendering loop
	while ( window->isOpen() ) {
		//	Start the current frame			

		//	Add text for FPS counter
		sf::Text fpsText;
		fpsText.setFont(font);
		fpsText.setCharacterSize(24);
		fpsText.setFillColor(sf::Color::Green);
		
		//	Add square
		sf::RectangleShape square(sf::Vector2f(50, 50));
		square.setPosition(600, 300);
		square.setFillColor(sf::Color::Red);

		//	End the current frame
		sf::Time elapsed = clock.restart();
		fpsText.setString(std::to_string(1.f / elapsed.asSeconds()));

		window->clear(sf::Color::White);

		window->draw(square);
		window->draw(fpsText);

		window->display();
	}
}

/*****************************************************************
*	@fn		main123
*
*	@brief	The main program
*	
*/
int main() {
	std::mutex programEnd;

	sf::RenderWindow window;
	window.create(sf::VideoMode(1280, 720), "Game", sf::Style::Default);
	//	change the position of the window (relatively to the desktop)
	window.setPosition(sf::Vector2i(500, 50));
	//	vertical synchronization enable
	window.setVerticalSyncEnabled(true);
	
	//	deactivate its OpenGL context
	window.setActive(false);
	//	launch the rendering thread
	std::thread thread(&threadRenderingWindow, &window);
	

	//	run the program as long as the window is open
	while ( window.isOpen() ) {

		//	check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;

		while ( window.pollEvent(event) ) {

			//	"close requested" event: closing the window
			if ( event.type == sf::Event::Closed ) {
				thread.detach();
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
					std::cout << "the ESC key was pressed" << std::endl;
					
					window.close();
					std::thread detach();
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
					std::cout << "the Mouse 4 button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
				if ( event.mouseButton.button == sf::Mouse::XButton2 ) {
					std::cout << "the Mouse 5 button was pressed" << std::endl;
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
	}

	return 0;
}

/*********************************************************************
*********************************************************************/