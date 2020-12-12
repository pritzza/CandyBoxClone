#pragma once

#include "Event.h"

class StateMachine;

enum STATE_EVENT_TYPE
{
	NO_STATE_ACTION,	// use this type for initializing static members
	ADD,
	REMOVE,
	CHANGE
};

class StateEvent : public Event
{
public:
	inline static StateMachine* sm;

	// members used for state changing/adding/removing
	const unsigned int id;
	const unsigned int actionType;

public:
	StateEvent(int id, int at) : id(id), actionType(at) {}

	void startGame();
	void handleEvent() override;
};