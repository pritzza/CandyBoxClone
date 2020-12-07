#include "MainState.h"

#include <iostream>

#include "../graphics/SpriteTexture.h"
#include "../graphics/SpriteSheet.h"

#include "../graphics/Window.h"

#include "../events/EventHandler.h"
#include "../events/StateEvent.h"
#include "../events/TabEvent.h"

#include "../player/Player.h"

#include "../graphics/Text.h"

MainState::MainState()
{
	init();
}

MainState::~MainState()
{
	
}

void MainState::init()
{
	eh->addEvent(new TabEvent(TAB_EVENT_TYPE::ADD_STARTING_TABS));
	eh->addEvent(new StateEvent(STATE::BATTLE, STATE_EVENT_TYPE::ADD));

	//ss->loadPlayerSprite();
}

void MainState::terminate()
{
	
}

void MainState::handleInput()
{
	//std::cout << "\nHandle Input()\n";
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		eh->addEvent(new StateEvent(STATE::BATTLE, STATE_EVENT_TYPE::CHANGE));

}

void MainState::update(const int FPS, const int tick)
{
	//std::cout << "\nUpdate()\n";

	p->update(FPS, tick);

	// also just some silly code
	if (tick % (FPS / 1) == 0)
	{
		if (playerX < Window::WINDOW_WIDTH)
			++playerX;
		else
			playerX = -3;
	}
}

void MainState::render()
{
	//std::cout << "\nRender()\n";
	w->clear();

	p->render(*w);

	w->draw();
}
