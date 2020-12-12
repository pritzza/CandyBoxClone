#include "StateEvent.h"

#include "../states/StateMachine.h"

#include "../states/State.h"

#include "../states/MainState.h"
#include "../states/BattleState.h"

void StateEvent::startGame()
{
	// set up first gamestate
	sm->addState(new MainState(), STATE::MAIN_STATE);
	sm->setState(id);
}

void StateEvent::handleEvent()
{
	switch (actionType)
	{
	case STATE_EVENT_TYPE::ADD:
		switch (id)
		{
		case STATE::MAIN_STATE:
			sm->addState(new MainState(), STATE::MAIN_STATE);
			break;
		case STATE::BATTLE_STATE:	// battle should never actually be passed, it should have a specification as to which battle
		case STATE::BATTLE_TEST_STATE:
			BattleState* temp = new BattleState;
			temp->init(STATE::BATTLE_TEST_STATE);

			sm->addState(temp, STATE::BATTLE_STATE);
			break;
		}
		break;

	case STATE_EVENT_TYPE::REMOVE:
		sm->removeState(id);
		sm->setState(STATE::MAIN_STATE);	// makes sure that when a state is deleted (say the battle state ends) that you aren't in an invalid state 
		break;

	case STATE_EVENT_TYPE::CHANGE:

		switch (id) // since we can pass specifications of battles, all of them go under battle state
		{
		case STATE::BATTLE_STATE:
		case STATE::BATTLE_TEST_STATE:
			sm->setState(STATE::BATTLE_STATE);
			break;
		default:
			sm->setState(id);
		}
	}
}
