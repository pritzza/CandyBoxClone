#include "EventHandler.h"

#include "Event.h"

#include "../states/StateMachine.h"
#include "../graphics/SpriteSheet.h"
#include "../graphics/Window.h"

EventHandler::~EventHandler()
{
	// double check that there's no events to prevent memory learks
	while (!(events.empty()))
		removeEvent();
}

void EventHandler::processEvents()
{
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

void EventHandler::removeEvent()
{
	delete events.back();
	events.pop_back();
}
