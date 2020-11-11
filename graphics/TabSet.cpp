#include "TabSet.h"

void TabSet::init(int w, int h)
{
	this->WW = w;
	this->WH = h;
}

void TabSet::update()
{
}

void TabSet::addTab(Tab t)
{
	tabs.push_back(t);
	updatePosition();
}

void TabSet::updatePosition()
{
	tabs.back().xPos = 0;
	tabs.back().yPos = 0;
}
