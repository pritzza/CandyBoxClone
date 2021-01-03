#pragma once

#include <vector>

#include "Tile.h"

class SpriteTexture
{
public:
	std::vector<Tile> texture;
	const int id;
	int width;
	int height;

public:
	SpriteTexture(int w, int h, int id) : texture(w*h), width(w), height(h), id(id) {}
	
};