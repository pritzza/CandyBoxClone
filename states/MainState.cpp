#include "MainState.h"

#include <iostream>

#include "../graphics/SpriteTexture.h"
#include "../graphics/SpriteSheet.h"

#include "../graphics/Window.h"

#include "../graphics/TabSet.h"

#include "../events/EventHandler.h"
#include "../events/StateEvent.h"


MainState::MainState(Window& w, SpriteSheet& s, EventHandler& e) : State(w, s, e)
{
	init();
}

MainState::~MainState()
{
	
}

void MainState::init()
{
	eh.addEvent(new StateEvent(STATE::BATTLE, STATE_EVENT_TYPE::ADD));

	ss.loadPlayerSprite();

	tabSet.init(ss, Window::WINDOW_WIDTH, Window::WINDOW_HEIGHT);
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
		if (playerX < Window::WINDOW_WIDTH)
			++playerX;
		else
			playerX = -3;
}

void MainState::render()
{
	Drawable a{ ss.getSprite(SPRITE::PLAYER), playerX, 5 };

	//std::cout << "\nRender()\n";
	w.clear();
	w.render(&a);

	tabSet.render(w);

	w.draw();
}
