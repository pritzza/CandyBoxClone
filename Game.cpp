#include "Game.h"

#include <chrono>
#include <iostream>

#include "states/State.h"
#include "events/StateEvent.h"
#include "events/TabEvent.h"
#include "graphics/Drawable.h"

void Game::start()
{
	this->running = true;

	// initialize all static State members
	State::w = &this->window;
	State::ss = &this->sheet;
	State::eh = &this->eventHandler;
	State::p = &this->player;

	// gives all drawable objects access to the spritesheet so they can load their own sprites
	Drawable::spriteSheet = &this->sheet;

	// initialize static members and add then change to STATE::MAIN
	StateEvent::sm = &this->stateMachine;
	StateEvent startingState{ STATE::NULL_STATE, STATE_EVENT_TYPE::NO_STATE_ACTION };
	startingState.startGame();

	// initilaize static members of TabEvent objects
	TabEvent tabEvent(&player.ui.ts, TAB_EVENT_TYPE::NO_TAB_ACTION);

	// finally initialize the player and start the gameloop!
	this->player.init();

	this->gameLoop();
}

void Game::gameLoop()
{
	std::chrono::time_point currentTime{ std::chrono::steady_clock::now() };
	std::chrono::duration elapsed{ std::chrono::steady_clock::now() - currentTime };

	int frames{};

	while (running)
	{
		elapsed = std::chrono::steady_clock::now() - currentTime;

		if (elapsed.count() / 1'000'000'000.0f > 1.0f / Game::FPS)	// if the time since last frame is greater than the game's frame rate
		{
			std::cout << frames << " / " << Game::FPS << " FPS : " << elapsed.count() / 1'000'000'000.0f << 
				" s, State: " << stateMachine.getCurrentStateID() << " : " << stateMachine.states.size() << " states, " << std::endl;

			currentTime = std::chrono::steady_clock::now();
			frames = 0;

			stateMachine.processStateChange();

			if (stateMachine.currentState() != nullptr)
			{
				stateMachine.currentState()->handleInput();
				stateMachine.currentState()->update(Game::FPS, tick);
				stateMachine.currentState()->render();
				
				eventHandler.processEvents();
			}
			++tick;
		}
		++frames;

		//if (tick == Game::FPS)
		//	running = false;
	}
}