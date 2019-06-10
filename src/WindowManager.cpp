#include "WindowManager.hpp"

namespace snp {

	WindowManager::WindowManager() :
		window(sf::VideoMode(1280, 720), "Default Name", sf::Style::Default) {

	}


	WindowManager::~WindowManager() {
	}

}
