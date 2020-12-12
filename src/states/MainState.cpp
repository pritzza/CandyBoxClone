#include "MainState.h"

#include <iostream>

#include "../graphics/SpriteTexture.h"
#include "../graphics/SpriteSheet.h"

#include "../graphics/Window.h"

#include "../events/EventHandler.h"
#include "../events/StateEvent.h"
#include "../events/TabEvent.h"

#include "../player/Player.h"

#include "../gui/Text.h"

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

	p->init();
	//ss->loadPlayerSprite();
}

void MainState::terminate()
{
	
}

void MainState::handleInput()
{
	//std::cout << "\nHandle Input()\n";
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		eh->addEvent(new StateEvent(STATE::BATTLE_TEST_STATE, STATE_EVENT_TYPE::ADD));
		eh->addEvent(new StateEvent(STATE::BATTLE_STATE, STATE_EVENT_TYPE::CHANGE));
	}
}

void MainState::update(const int FPS, const int tick)
{
	//std::cout << "\nUpdate()\n";

	p->update(FPS, tick);

	// also just some silly code
	if (tick % (FPS / 1) == 0)
	{

	}
}

void MainState::render()
{
	//std::cout << "\nRender()\n";
	w->clear();

	p->render(*w);

	w->draw();
}
