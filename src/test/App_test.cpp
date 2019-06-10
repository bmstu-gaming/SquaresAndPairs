
#include <iostream>

#include "App.hpp"

void example_App() {
	using namespace snp;

	App* s = App::getInstance();
	App* r = App::getInstance();

	std::cout << s << std::endl;
	std::cout << r << std::endl;

}