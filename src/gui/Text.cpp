#include "Text.h"

#include "../graphics/SpriteTexture.h"

void Text::update()
{
	updateSprite();
}

void Text::updateSprite()
{
	const unsigned int& b{ beginning.length() };	// beginning length
	const unsigned int& q{ std::to_string(quantity).length() };	// number of digits in quantity
	const unsigned int& e{ end.length() };	// end length

	sprite->width = b + q + e;
	sprite->texture.resize(sprite->width);

	text = beginning + std::to_string(quantity) + end;

	for (int i = 0; i < text.length(); ++i)
		sprite->texture[i].symbol = text[i];
}
