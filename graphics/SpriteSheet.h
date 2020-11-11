#pragma once

#include <unordered_map>

#include "SpriteTexture.h"

class SpriteSheet
{
public:
	std::unordered_map<int, SpriteTexture> sprites;

public:
	SpriteSheet();

	// returns sprite* from unordered map under the id key
	SpriteTexture* getSprite(int id);

	// puts spriteTexture into unordered map behind unique id key
	int loadPlayerSprite();
	int loadMainTabSprite();

private:
	void addSprite(int id, SpriteTexture&& sprite);

};