#pragma once

#include "../gui/PlayerUI.h"

#include "Resources.h"

class Window;
class EventHandler;

class Player
{
public:
	EventHandler& eh;

	Resources resources;
	PlayerUI ui{ resources };
	int maxHealth{ 100 };
	int health{ maxHealth };

public:
	Player(EventHandler& eh) : eh(eh) { }

	void init();

	void update(const int FPS, const int tick);
	void render(Window& w);
};