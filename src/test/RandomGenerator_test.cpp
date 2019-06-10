
#include <iostream>

#include "RandomGenerator.hpp"

void example_rg() {
	int intervalA = 1;
	int intervalB = 6;
	int seed = 228;

	snp::RandomGenerator rg(seed);
	rg.setInterval(intervalA, intervalB);

	//generate numbers
	std::cout << rg() << rg() << std::endl;
}

