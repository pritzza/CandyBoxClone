#pragma once

#include <vector>

#include "graphics/Window.h"
#include "graphics/SpriteSheet.h"
#include "states/StateMachine.h"
#include "events/EventHandler.h"

class Game
{
public:
	Window window;
	SpriteSheet sheet;
	StateMachine stateMachine;
	EventHandler eventHandler{ window, sheet, stateMachine };

	static constexpr int FPS{ 24 };
	unsigned int frame{ 0 };
	unsigned int tick{ 0 };
	bool running{ false };
	
public:
	void start();
	void gameLoop();
	
};