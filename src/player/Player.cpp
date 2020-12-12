#include "Player.h"

#include "../graphics/Window.h"
#include "../graphics/SpriteSheet.h"

void Player::init()
{
	ui.init();
}

void Player::update(const int FPS, const int tick)
{
	this->ui.update();

	if (tick % (FPS / 1) == 0)	// once every second
		resources.increment();
}

void Player::render(Window& w)
{
	ui.render(w);
}
