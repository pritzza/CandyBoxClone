#include "PlayerUI.h"

#include "../graphics/Window.h"

void PlayerUI::init()
{
	int x{ 2 };
	int y{ 4 };
	candies.sprite = Drawable::spriteSheet->getSprite(Drawable::spriteSheet->loadCandiesCounterSprite());
	candies.setPos(x, y);

	lollipops.sprite = Drawable::spriteSheet->getSprite(Drawable::spriteSheet->loadLollipopsCounterSprite());
	lollipops.setPos(x, y + 1);
}

void PlayerUI::update()
{
	this->candies.update();
	this->lollipops.update();
	//this->ts.update();
}

void PlayerUI::render(Window& w)
{
	ts.render(w);
	w.render(&this->candies);
	w.render(&this->lollipops);
}