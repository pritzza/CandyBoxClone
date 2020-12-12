#include "TabSet.h"

#include "SpriteTexture.h"
#include "SpriteSheet.h"
#include "Window.h"

void TabSet::init(SpriteSheet& ss, int w, int h)
{
	this->ss = &ss;
	this->WW = w;
	this->WH = h;

	Tab mt(ss.getSprite(ss.loadMainTabSprite()), TABS::MAIN_TAB);
	Tab ot(ss.getSprite(ss.loadOtherTabSprite()), TABS::OTHER);
	Tab lt(ss.getSprite(ss.loadLastTabSprite()), TABS::LAST);

	mt.setVisibility(true);
	ot.setVisibility(true);
	lt.setVisibility(true);

	addTab(mt);
	addTab(ot);
	addTab(lt);
}

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
