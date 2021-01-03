#pragma once

#include "Mesh.h"
#include "../entities/Entity.h"

class Window;
class SpriteTexture;

class Area
{
public:
	Mesh* map;
	Entity player{ nullptr, 0, 0 };

public:
	~Area();

	void loadArea(const int id);

	void render(Window& w);

private:
	void initPlayer(SpriteTexture* s, int startingX, int startingY);
	void loadFromFile(const char* fileName);
};