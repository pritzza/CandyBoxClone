#pragma once

class Resources
{
public:
	int candies{};
	int candiesPerSecond{ 1 };
	int lollipops{};
	int lollipopsPerSecond{ 0 };

public:
	void increment();
};