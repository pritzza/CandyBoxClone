#pragma once

#include <vector>

#include "Tab.h"

enum TABS
{
	MAIN_TAB,	// _TAB suffix to prevent name collision
	OTHER,
	LAST,
};

class Window;
class SpriteSheet;

class TabSet
{
public:
	SpriteSheet* ss;

	std::vector<Tab> tabs;
	int WW;
	int WH;

public:
	void init(SpriteSheet& ss, int w, int h);

	void update();
	void render(Window& w);

	void addTab(Tab t);
	void updatePosition();
};