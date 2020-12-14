#pragma once
#include <random>
class Random {
	std::random_device dev;
public:
	int Nextnum(int min, int max) {
		std::mt19937 rng(dev());
		if (min == max) return min;
		std::uniform_int_distribution</*std::mt19937::result_type*/> dist6(min, max - 1);
		return dist6(rng);
	}
};


