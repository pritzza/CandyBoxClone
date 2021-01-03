#include "EventHandler.h"

#include <algorithm>

#include "Event.h"

EventHandler::~EventHandler()
{
	// double check that there's no events to prevent memory learks
	while (!(events.empty()))
		removeEvent();
}

void EventHandler::processEvents()
{
	// EH is a stack, FILO, so i need to reverse events to execute them in the order in which they're called
	reverseEvents();

	// iterate through events in a stack like fashion (.back()) then deallocate
	while (!(events.empty()))
	{
		events.back()->handleEvent();
		removeEvent();
	}
}

void EventHandler::addEvent(Event* e)
{
	events.push_back(e);
}

void EventHandler::reverseEvents()
{
	std::reverse(this->events.begin(), this->events.end());
}

void EventHandler::removeEvent()
{
	delete events.back();
	events.pop_back();
}
