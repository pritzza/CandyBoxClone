#pragma once

#include <vector>

#include "../src/graphics/Window.h"
#include "../src/graphics/SpriteSheet.h"
#include "../src/states/StateMachine.h"
#include "../src/events/EventHandler.h"

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