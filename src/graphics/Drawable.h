#pragma once

class SpriteTexture;
class SpriteSheet;

class Drawable
{
public:
	// giving all drawables access to SpriteSheet so they can load their own sprites so i dont need to pass a bunch of ptrs or refs of spritesheet everywhere
	inline static SpriteSheet* spriteSheet;

	SpriteTexture* sprite;
	int xPos;
	int yPos;
	bool reverse{ false };

public:
	Drawable(SpriteTexture* sprite, int xPos, int yPos) : sprite(sprite), xPos(xPos), yPos(yPos) {}

	// moves to absolute pos
	void setPos(int x, int y) { this->xPos = x;		this->yPos = y; }
	// moves based on relative position
	void move(int x, int y)   { this->xPos += x;	this->yPos += y; }
};