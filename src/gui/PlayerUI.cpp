#include "PlayerUI.h"

#include "../graphics/Window.h"

void PlayerUI::init()
{
	int x{ 2 };
	int y{ 6 };

	candies.sprite = Drawable::spriteSheet->getSprite(Drawable::spriteSheet->loadSprite(SPRITE::CANDIES_COUNTER_SPRITE));
	candies.setPos(x, y);
	
	lollipops.sprite = Drawable::spriteSheet->getSprite(Drawable::spriteSheet->loadSprite(SPRITE::LOLLIPOPS_COUNTER_SPRITE));
	lollipops.setPos(x, y + 1);
}

void PlayerUI::update()
{
	this->candies.update();		// update just calls updateSprite()
	this->lollipops.update();
	
	//this->ts.update();
}

void PlayerUI::render(Window& w)
{
	ts.render(w);
	w.render(&this->candies);
	w.render(&this->lollipops);
}