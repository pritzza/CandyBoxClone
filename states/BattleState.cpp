#include "../../src/states/BattleState.h"

#include <iostream>

#include "../../src/graphics/SpriteTexture.h"
#include "../../src/graphics/SpriteSheet.h"
#include "../../src/events/EventHandler.h"
#include "../../src/graphics/Window.h"

#include "../../src/events/StateEvent.h"

BattleState::BattleState(Window& w, SpriteSheet& s, EventHandler& e) : State(w, s, e)
{
	init();
}

BattleState::~BattleState()
{
	terminate();
}

void BattleState::init()
{

}

void BattleState::terminate()
{
}

void BattleState::handleInput()
{
	//std::cout << "\nHandle Input()\n";
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		eh.addEvent(new StateEvent(STATE::MAIN, STATE_EVENT_TYPE::CHANGE));
}

void BattleState::update(const int FPS, const int tick)
{
	//std::cout << "\nUpdate()\n";
}

void BattleState::render()
{
	//std::cout << "\nRender()\n";
	w.clear();
	//w.render(&player);
	w.draw();
}