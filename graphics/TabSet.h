#pragma once

#include <vector>

#include "Tab.h"

class TabSet
{
public:
	std::vector<Tab> tabs;
	int WW;
	int WH;

public:
	void init(int w, int h);

	void update();
	
	void addTab(Tab t);
	void updatePosition();
};