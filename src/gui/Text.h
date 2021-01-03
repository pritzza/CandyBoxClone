#pragma once

#include "../graphics/Drawable.h"

#include <string>

class SpriteTexture;

class Text : public Drawable
{
	const std::string beginning;	// you have
	const std::string end;			// candies
	int& quantity;					// 153
	int digits;						// 3

	std::string text;				// you have 153 candies

public:
	Text(const int x, const int y, const std::string& beginning, int& quantity, const std::string& end, SpriteTexture* sprite) :
		Drawable{ sprite, x, y }, 
		beginning(beginning),
		quantity(quantity), 
		end(end) 
	{}

	void update();
	void updateSprite();	// the sprites of Text have to be updated every time their quantity is incremented
};