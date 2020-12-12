#pragma once

#include <vector>

#include "Tab.h"

enum TABS
{
	MAIN_TAB_ID,	// _TAB_ID suffix to prevent name collision
	OTHER_TAB_ID,
	LAST_TAB_ID,
};

class Window;

class TabSet
{
public:
	std::vector<Tab> tabs;
	int WW;	// window width
	int WH;	// window height

public:
	TabSet(int w, int h) : WW(w), WH(h) {}

	void update();
	void render(Window& w);

	void addTab(Tab t);
	void updatePosition();
};