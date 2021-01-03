#include "../states/BattleState.h"

#include <iostream>

#include "../graphics/SpriteTexture.h"
#include "../graphics/SpriteSheet.h"
#include "../events/EventHandler.h"
#include "../graphics/Window.h"
#include "../events/StateEvent.h"

BattleState::~BattleState()
{
	terminate();
}

void BattleState::init(int areaID)
{
	this->area.loadArea(areaID);
}

void BattleState::terminate()
{
}

void BattleState::handleInput()
{
	//std::cout << "\nHandle Input()\n";
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		eh->addEvent(new StateEvent(STATE::BATTLE_STATE, STATE_EVENT_TYPE::REMOVE));

	// arrow key movement for player
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		area.player.move(0, -1);
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		area.player.move(0, 1);
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		area.player.move(-1, 0);
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		area.player.move(1, 0);
}

void BattleState::update(const int FPS, const int tick)
{
	//std::cout << "\nUpdate()\n";

	area.player.update(*area.map);
}

void BattleState::render()
{
	//std::cout << "\nRender()\n";
	w->clear();

	area.render(*w);

	//w.render(&player);
	w->draw();
}