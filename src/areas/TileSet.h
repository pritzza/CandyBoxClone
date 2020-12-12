#pragma once

class Tile;

class TileSet
{
public:
	int width{ 0 };
	int height{ 0 };
	Tile* tiles = nullptr;

public:
	~TileSet();

	void loadTest();

private:
	void loadArea(const char* fileName);
};