#pragma once

class SpriteTexture;
class SpriteSheet;

class Drawable
{
public:
	// giving all drawables access to SpriteSheet so they can load their own sprites so i dont need to pass a bunch of ptrs or refs of spritesheet everywhere
	// ive been told this is a bad design/anti pattern, but im not up for making this perfect, i care more about this just working lol
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