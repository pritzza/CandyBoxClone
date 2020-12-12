#pragma once

#include <unordered_map>

#include "SpriteTexture.h"

enum SPRITE
{
	PLAYER,
	MAIN_TAB_not_a_solution,
	OTHER_TAB,
	LAST_TAB,
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

private:
	void addSprite(int id, SpriteTexture* sprite);

};