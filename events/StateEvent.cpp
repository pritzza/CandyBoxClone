#include "StateEvent.h"

#include "../states/StateMachine.h"
#include "../states/State.h"
#include "../states/MainState.h"
#include "../states/BattleState.h"

void StateEvent::init(Window* w, SpriteSheet* ss, EventHandler* eh, StateMachine* sm)
{
	// assign static members
	this->w = w;
	this->ss = ss;
	this->eh = eh;
	this->sm = sm;

	// set up first gamestate
	sm->addState(new MainState(*w, *ss, *eh), STATE::MAIN);
	sm->setState(id);
}

void StateEvent::handleEvent()
{
	switch (actionType)
	{
	case STATE_EVENT_TYPE::ADD:
		switch (id)
		{
		case STATE::MAIN:
			sm->addState(new MainState(*w, *ss, *eh), STATE::MAIN);
			break;
		case STATE::BATTLE:
			sm->addState(new BattleState(*w, *ss, *eh), STATE::BATTLE);
			break;
		}
		break;

	case STATE_EVENT_TYPE::REMOVE:
		sm->removeState(id);
		break;

	case STATE_EVENT_TYPE::CHANGE:
		sm->setState(id);
		break;
	}
}
