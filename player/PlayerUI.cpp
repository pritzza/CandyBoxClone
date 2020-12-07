#include "PlayerUI.h"

#include "../graphics/Window.h"

void PlayerUI::init()
{
	resText.sprite = Drawable::spriteSheet->getSprite(Drawable::spriteSheet->loadCandiesTextSprite());
}

void PlayerUI::update()
{
	this->resText.update();
	//this->ts.update();
}

void PlayerUI::render(Window& w)
{
	ts.render(w);
	w.render(&this->resText);
}