#pragma once

class Tile
{
public:
	char symbol{ '&' };
	bool solid{ true };

public:
	void init(char sy, bool so) { this->symbol = sy; this->solid = so; }
};