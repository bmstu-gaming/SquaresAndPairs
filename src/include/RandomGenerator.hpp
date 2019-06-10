#pragma once

#include <random>

namespace snp {

	class RandomGenerator {
	public:
		RandomGenerator();
		~RandomGenerator();

		RandomGenerator(unsigned int seed);

		void setInterval(unsigned int a, unsigned int b);
		unsigned int operator()();

	private:
		std::mt19937 generator;
		std::uniform_int_distribution<unsigned int> distribution;
	};
}
