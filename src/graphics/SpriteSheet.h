#pragma once

#include <unordered_map>

#include "SpriteTexture.h"

enum SPRITE
{
	PLAYER_SPRITE,
	MAIN_TAB_SPRITE,	// i desperatly need to rename these to prevent enum name collisions
	OTHER_TAB_SPRITE,
	LAST_TAB_SPRITE,
	CANDIES_COUNTER_SPRITE,
	LOLLIPOPS_COUNTER_SPRITE
};

class SpriteSheet
{
public:
	std::unordered_map<int, SpriteTexture*> sprites;

public:
	~SpriteSheet();

	void terminate();

	// returns sprite* from unordered map under the id key
	SpriteTexture* getSprite(int id);

	// puts spriteTexture into unordered map behind unique id key
	int loadPlayerSprite();				// test sprite
	int loadMainTabSprite();			// HUD
	int loadOtherTabSprite();			// test tab
	int loadLastTabSprite();			// test tap
	int loadCandiesCounterSprite();		// player ui
	int loadLollipopsCounterSprite();	// player ui

private:
	void addSprite(int id, SpriteTexture* sprite);

};