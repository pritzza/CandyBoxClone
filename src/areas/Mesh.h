#pragma once

#include "../graphics/Drawable.h"
#include "../graphics/SpriteTexture.h"

#include "SpecialTiles.h"

#include <vector>

class Mesh : public Drawable
{
public:
	std::vector<SpecialTile> specialTiles;

public:
	Mesh(SpriteTexture* s, int x, int y) : Drawable{ s, x, y }, specialTiles(s->width * s->height) { }
};