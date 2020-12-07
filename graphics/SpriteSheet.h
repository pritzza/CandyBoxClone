#pragma once

#include <unordered_map>

#include "SpriteTexture.h"

enum SPRITE
{
	PLAYER_SPRITE,
	MAIN_TAB_SPRITE,	// i desperatly need to rename these to prevent enum name collisions
	OTHER_TAB_SPRITE,
	LAST_TAB_SPRITE,
	CANDIES_SPRITE,
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
	int loadPlayerSprite();
	int loadMainTabSprite();
	int loadOtherTabSprite();
	int loadLastTabSprite();
	int loadCandiesTextSprite();

private:
	void addSprite(int id, SpriteTexture* sprite);

};