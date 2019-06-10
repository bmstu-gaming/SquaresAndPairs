#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace snp {

class WindowManager {
public:
	WindowManager();
	~WindowManager();

private:
	sf::RenderWindow window;
};

}
