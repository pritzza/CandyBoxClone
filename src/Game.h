#pragma once

#include <vector>

#include "graphics/Window.h"
#include "graphics/SpriteSheet.h"
#include "states/StateMachine.h"
#include "player/Player.h"
#include "events/EventHandler.h"

class Game
{
public:
	inline static Window window;
	inline static SpriteSheet sheet;
	inline static StateMachine stateMachine;
	inline static EventHandler eventHandler;

	inline static Player player{ eventHandler };

	static constexpr int FPS{ 24 };
	unsigned int frame{ 0 };
	unsigned int tick{ 0 };
	bool running{ false };
	
public:
	void start();
	void gameLoop();
	
};