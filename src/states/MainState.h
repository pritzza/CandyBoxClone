#pragma once

#include "State.h"

#include "../gui/TabSet.h"

class MainState : public State
{
public:

public:
	MainState();
	~MainState() override;

	void virtual init();
	void virtual terminate();

	void virtual handleInput();
	void virtual update(const int FPS, const int tick);
	void virtual render();
};