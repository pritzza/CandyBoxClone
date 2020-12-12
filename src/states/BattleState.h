#pragma once

#include "State.h"

#include "../areas/Area.h"

enum BATTLES
{
	BATTLE_TEST
};

class BattleState : public State
{
public:
	Area area;

public:
	~BattleState() override;

	void virtual init() {}
	void init(int areaID);
	void virtual terminate();

	void virtual handleInput();
	void virtual update(const int FPS, const int tick);
	void virtual render();
};