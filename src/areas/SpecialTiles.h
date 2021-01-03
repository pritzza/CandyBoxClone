#pragma once

enum SPECIAL_TILE
{
	NORMAL_TILE,
	EXIT_TILE,
	SECRET_EXIT_TILE,
	EVENT_1_TILE,	// counting from one because screw you
	EVENT_2_TILE,	// allow for arbitrary ammount of area specific events that specials tiles can do
	EVENT_3_TILE,	// i can make these enemy spawns
	EVENT_4_TILE,	// chests the player opens that give items
	EVENT_5_TILE,	// heal the player
	EVENT_6_TILE,	// kill the player
	EVENT_7_TILE,	// do something else
	EVENT_8_TILE,	// whatever i can think of, yk
	EVENT_9_TILE,	// i just throw some kind of Event to the EventHandler
};

class SpecialTile 
{
public:
	int type{ SPECIAL_TILE::NORMAL_TILE };	// identifies what type of special tile it is
	bool triggerState{ false };						// has the tile been triggered once
	bool repeatable{ false };					// can it be proced multiple times
	int delay{ 0 };							// frames between touching tile and something happening
	int cooldown{ 24 };						// frames between something happening and when the tile can be interacted with again
	int delayCounter{ 0 };							// keeps track where we are in delay
	int cooldownCounter{ 0 };						// keeps track where we are in cooldown

public:
	void init(const char c);
	void collide();
};