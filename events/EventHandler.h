#pragma once

#include <vector>

class Event;
class StateMachine;
class Window;
class SpriteSheet;

class EventHandler
{
public:
	std::vector<Event*> events;

	StateMachine& sm;
	Window& w;
	SpriteSheet& ss;

public:
	EventHandler(Window& w, SpriteSheet& ss, StateMachine& sm) : w(w), ss(ss), sm(sm) {}
	~EventHandler();

	void processEvents();
	void addEvent(Event* e);
	void removeEvent();
};