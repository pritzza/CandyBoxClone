#pragma once

#include <memory>

class SpriteTexture
{
public:
	std::unique_ptr<char[]> texture;
	const int id;
	int width;
	int height;

public:
	SpriteTexture(int w, int h, int id) : width(w), height(h), id(id), texture(new char[width * height]) {}

};