#pragma once

class SpriteTexture;

class Drawable
{
public:
	SpriteTexture* sprite;
	int xPos;
	int yPos;
public:
	Drawable(SpriteTexture* sprite, int xPos, int yPos) : sprite(sprite), xPos(xPos), yPos(yPos) {}
};