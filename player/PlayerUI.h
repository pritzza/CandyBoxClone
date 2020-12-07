#pragma once

#include "../graphics/Text.h"
#include "../graphics/TabSet.h"

#include "../graphics/SpriteSheet.h"

#include "../graphics/Window.h"

#include "Resources.h"

class PlayerUI
{
public:
	Resources& rs;
	TabSet ts{ Window::WINDOW_WIDTH, Window::WINDOW_HEIGHT };
	Text resText{ 3, 5, "You have ", rs.candies, " candies!", nullptr};

public:
	PlayerUI(Resources& rs) : rs(rs) { }

	void init();

	void update();
	void render(Window& w);
};