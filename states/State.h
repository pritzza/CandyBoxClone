#pragma once

//#include "../graphics/TabSet.h"

enum STATE
{
	NULL_STATE,	// default value of add/removeID to prevent mistakes in state adding/removing
	MAIN,
	MAP,
	BATTLE,
};

class Window;
class SpriteSheet;
class EventHandler;
class TabSet;

class State
{
public:
	Window& w;
	SpriteSheet& ss;
	EventHandler& eh;

	//inline static TabSet ts;

public:
	State(Window& w, SpriteSheet& ss, EventHandler& eh) : w(w), ss(ss), eh(eh) { }
	virtual ~State() = default;

	void virtual init() = 0;		// loads and sets up everything the state needs
	void virtual terminate() = 0;	// incase of heap allocation

	void virtual handleInput() = 0;	// makes events based on keyboard input
	void virtual update(const int FPS, const int tick) = 0;	// updates all objects of state
	void virtual render() = 0;		// draws contents of the state to the window
};