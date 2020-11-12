#include "Game.h"

#include <chrono>
#include <iostream>

#include "states/State.h"
#include "events/StateEvent.h"
#include "states/MainState.h"

void Game::start()
{
	this->running = true;

	// initialize static members and add then change to STATE::MAIN
	StateEvent* startingState = new StateEvent(STATE::NULL_STATE, STATE_EVENT_TYPE::NO_ACTION);
	startingState->init(&window, &sheet, &eventHandler, &stateMachine);

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
				" s, State: " << stateMachine.getCurrentStateID() << " : " << stateMachine.states.size() << " states, " << 
				eventHandler.events.size() << " events" << std::endl;

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