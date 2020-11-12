#pragma once

#include "State.h"

#include "../graphics/TabSet.h"

class MainState : public State
{
public:
	TabSet tabSet;
	int playerX{};

public:
	MainState(Window& window, SpriteSheet& s, EventHandler& e);
	~MainState() override;

	void virtual init();
	void virtual terminate();

	void virtual handleInput();
	void virtual update(const int FPS, const int tick);
	void virtual render();
};