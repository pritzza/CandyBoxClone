#pragma once

#include <vector>

class Event;

class EventHandler
{
public:
	std::vector<Event*> events;

public:
	~EventHandler();

	void processEvents();
	void addEvent(Event* e);

private:
	void reverseEvents();
	void removeEvent();
};