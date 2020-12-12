#pragma once

#include "Event.h"

class TabSet;

enum TAB_EVENT_TYPE
{
	NO_TAB_ACTION,	// use this type for initializing static members
	ADD_STARTING_TABS,
};

class TabEvent : public Event
{
public:
	inline static TabSet* ts;
	const unsigned int actionType;

public:
	TabEvent(int at) : actionType(at) {}
	TabEvent(TabSet* ts, int at) : actionType(at) { this->ts = ts; }

	void addStartingTabs();

	void handleEvent() override;
};