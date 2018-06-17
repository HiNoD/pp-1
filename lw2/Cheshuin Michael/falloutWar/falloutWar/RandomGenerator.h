#pragma once
#include "stdafx.h"

class RandomGenerator
{
public:
	RandomGenerator() = default;
	RandomGenerator(std::mt19937::result_type seed) : eng(seed) {}
	int GetRandomInt(int min, int max);

private:
	std::mt19937 eng{ std::random_device{}() };
};

int RandomGenerator::GetRandomInt(int min, int max)
{
	return std::uniform_int_distribution<int>{min, max}(eng);
}