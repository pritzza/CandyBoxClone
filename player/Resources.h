#pragma once

class Resources
{
public:
	int candies{};
	int candiesPerSecond{ 1 };

public:
	Resources(int c, int cps) : candies(c), candiesPerSecond(cps) {}
	Resources() {}

	void increment();
};