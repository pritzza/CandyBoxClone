#pragma once

#include <unordered_map>

#include "SpriteTexture.h"

enum SPRITE
{
	PLAYER_SPRITE,
	PLAYER_FACE_SPRITE,
	MAIN_TAB_SPRITE,
	OTHER_TAB_SPRITE,
	LAST_TAB_SPRITE,
	CANDIES_COUNTER_SPRITE,
	LOLLIPOPS_COUNTER_SPRITE,
	JON_SPRITE,
	GUY_SPRITE,
};

class SpriteSheet
{
public:
	std::unordered_map<int, SpriteTexture*> sprites;

public:
	~SpriteSheet();

	// returns sprite* from unordered map under the id key
	SpriteTexture* getSprite(int id);

	int loadSprite(int id);

	void removeSprite(int id);

private:
	void addSprite(int id, SpriteTexture* sprite);
	void loadFromFile(const char* fileName, const int id);
	void terminate();
};