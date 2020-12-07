#include "TabSet.h"

#include "SpriteSheet.h"

#include "Window.h"

void TabSet::update()
{
	// if a tab is clicked, do click()
}

void TabSet::render(Window& w)
{
	for (Tab& t : tabs)
		if (t.visible)
			w.render(&t);
}

void TabSet::addTab(Tab t)
{
	tabs.push_back(t);
	updatePosition();
}

void TabSet::updatePosition()
{
	int totalWidth{};

	for (Tab& t : tabs)
		totalWidth += t.sprite->width;

	for (int i = 0; i < tabs.size(); ++i)
		if (i > 0)
			tabs[i].xPos = tabs[i - 1].xPos + tabs[i - 1].sprite->width;
		else
			tabs[i].xPos = (WW/2) - (totalWidth / 2);
}
