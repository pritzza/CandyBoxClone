#pragma once

#include "../gui/Text.h"
#include "../gui/TabSet.h"

#include "../graphics/SpriteSheet.h"

#include "../graphics/Window.h"

#include "../player/Resources.h"

class PlayerUI
{
public:
	Resources& rs;
	TabSet ts{ Window::WINDOW_WIDTH, Window::WINDOW_HEIGHT };
	Text candies{ 0, 0, "You have ", rs.candies, " candies!", nullptr };
	Text lollipops{ 0, 0, "You have ", rs.lollipops, " lollipops!", nullptr };

public:
	PlayerUI(Resources& rs) : rs(rs) { }

	void init();

	void update();
	void render(Window& w);
};