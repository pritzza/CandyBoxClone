#pragma once

class EventHandler;

class Event
{
private:
	static inline EventHandler* eh;	// all evenets need access to the event handler

public:
	void virtual handleEvent() = 0;
};