#pragma once

#include "../graphics/Drawable.h"

class SpriteTexture;
class Mesh;
class Window;

class Entity
{
public:
	Drawable model;
	int xVel{ 0 };
	int yVel{ 0 };

public:
	Entity(SpriteTexture* s, int x, int y) : model(s, x, y) {}

	void update(Mesh& m);
	void move(int xVel, int yVel);

	void render(Window& w);

private:
	void updatePosition(Mesh& m);
	void isColliding(Mesh& m, bool& c);
};
