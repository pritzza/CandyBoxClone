#include "../../src/states/MainState.h"

#include <iostream>

#include "../../src/graphics/SpriteTexture.h"
#include "../../src/graphics/SpriteSheet.h"

#include "../../src/graphics/Window.h"

#include "../../src/events/EventHandler.h"
#include "../../src/events/StateEvent.h"

#include "../graphics/TabSet.h"
//#include "../graphics/Tab.h"

MainState::MainState(Window& w, SpriteSheet& s, EventHandler& e) : State(w, s, e)
{
	init();
}

MainState::~MainState()
{
	terminate();
}

void MainState::init()
{
	eh.addEvent(new StateEvent(STATE::BATTLE, STATE_EVENT_TYPE::ADD));

	//ss.loadPlayerSprite();
	//Tab t(ss.getSprite(ss.loadMainTabSprite()), 0);	// this is the line where eveything goes wrong
}

void MainState::terminate()
{
}

void MainState::handleInput()
{
	//std::cout << "\nHandle Input()\n";
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		eh.addEvent(new StateEvent(STATE::BATTLE, STATE_EVENT_TYPE::CHANGE));
}

void MainState::update(const int FPS, const int tick)
{
	//std::cout << "\nUpdate()\n";
	if (tick % FPS == 0)
		;
}

void MainState::render()
{
	//Drawable a{ ss.getSprite(0), 0,0 };

	//std::cout << "\nRender()\n";
	w.clear();
	//w.render(&a);
	w.draw();
}
