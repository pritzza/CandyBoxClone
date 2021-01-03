#pragma once

// a tile represents a single character of a sprite. Every game entity has a sprite which is made up of a vector of tiles
class Tile
{
public:
	char symbol{ '?' };	// each "pixel" or tile of a sprite has a visual ASCII representation
	bool solid{ true };	// each "pixel" or tile of a sprite also has a value whether its solid, this is used for clicking collision and combat collision

public:
	void init(char sy, bool so) { this->symbol = sy; this->solid = so; }
};