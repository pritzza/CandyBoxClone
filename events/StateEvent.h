#pragma once

#include "Event.h"

class Window;
class SpriteSheet;
class EventHandler;

class StateMachine;

enum STATE_EVENT_TYPE
{
	NO_ACTION,	// use this type for initializing static members
	ADD,
	REMOVE,
	CHANGE
};

class StateEvent : public Event
{
public:
	// boilerplate needed for every state
	inline static Window* w;
	inline static SpriteSheet* ss;
	inline static EventHandler* eh;
	inline static StateMachine* sm;

	// members used for state changing/adding/removing
	const unsigned int id;
	const unsigned int actionType;

public:
	StateEvent(int id, int at) : id(id), actionType(at) {}
	StateEvent(Window* w, SpriteSheet* ss, EventHandler* eh, StateMachine* sm, int id, int at) :
		id(id), 
		actionType(at) 
	{ init(w, ss, eh, sm); }

	void init(Window* w, SpriteSheet* ss, EventHandler* eh, StateMachine* sm);
	void handleEvent() override;
};