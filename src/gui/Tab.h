#pragma once

#include "../graphics/Drawable.h"

class EventHandler;

class Tab : public Drawable
{
public:
	inline static EventHandler* eh;

	int stateID;
	bool visible{ false };

public:
	Tab(SpriteTexture* sprite, int stateID) : Drawable{ sprite, 0, 0 }, stateID(stateID) {}

	void click();
	void setVisibility(bool visible);

};