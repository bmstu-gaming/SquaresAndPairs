#include "RandomGenerator.hpp"

namespace snp {

	RandomGenerator::RandomGenerator() {
		std::random_device rd;
		generator = std::mt19937(rd());
	}

	RandomGenerator::~RandomGenerator() {
	}

	RandomGenerator::RandomGenerator(unsigned int seed) {
		generator = std::mt19937(seed);
	}

	void RandomGenerator::setInterval(unsigned int a, unsigned int b) {
		distribution = std::uniform_int_distribution<unsigned int>(a, b);
	}

	unsigned int RandomGenerator::operator()() {
		return distribution(generator);
	}

}
