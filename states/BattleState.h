#pragma once

#include "../../src/states/State.h"

class BattleState : public State
{
public:


public:
	BattleState(Window& window, SpriteSheet& s, EventHandler& e);
	~BattleState() override;

	void virtual init();
	void virtual terminate();

	void virtual handleInput();
	void virtual update(const int FPS, const int tick);
	void virtual render();
};