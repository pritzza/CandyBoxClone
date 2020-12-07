#pragma once

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
class Player;

class State
{
public:
	inline static Window* w;
	inline static SpriteSheet* ss;
	inline static EventHandler* eh;
	inline static Player* p;

public:
	virtual ~State() = default;

	void virtual init() = 0;		// loads and sets up everything the state needs
	void virtual terminate() = 0;	// incase of heap allocation

	void virtual handleInput() = 0;	// makes events based on keyboard input
	void virtual update(const int FPS, const int tick) = 0;	// updates all objects of state
	void virtual render() = 0;		// draws contents of the state to the window
};