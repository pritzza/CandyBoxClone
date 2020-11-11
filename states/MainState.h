#pragma once

#include "../../src/states/State.h"

class MainState : public State
{
public:
	// members

public:
	MainState(Window& window, SpriteSheet& s, EventHandler& e);
	~MainState();

	void virtual init();
	void virtual terminate();

	void virtual handleInput();
	void virtual update(const int FPS, const int tick);
	void virtual render();
};