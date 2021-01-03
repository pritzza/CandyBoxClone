#include "SpecialTiles.h"

#include <iostream>

void SpecialTile::init(const char c)
{
	switch (c)
	{
	case 'e': type = SPECIAL_TILE::EXIT_TILE;			break;
	case 'E': type = SPECIAL_TILE::SECRET_EXIT_TILE;	break;
	case '1': type = SPECIAL_TILE::EVENT_1_TILE;		break;
	case '2': type = SPECIAL_TILE::EVENT_2_TILE;		break;
	case '3': type = SPECIAL_TILE::EVENT_3_TILE;		break;
	case '4': type = SPECIAL_TILE::EVENT_4_TILE;		break;
	case '5': type = SPECIAL_TILE::EVENT_5_TILE;		break;
	case '6': type = SPECIAL_TILE::EVENT_6_TILE;		break;
	case '7': type = SPECIAL_TILE::EVENT_7_TILE;		break;
	case '8': type = SPECIAL_TILE::EVENT_8_TILE;		break;
	case '9': type = SPECIAL_TILE::EVENT_9_TILE;		break;
	default:  type = SPECIAL_TILE::NORMAL_TILE;
	}
}

void SpecialTile::collide()
{
	switch (type)
	{
	case SPECIAL_TILE::NORMAL_TILE:
		std::cout << "nothing";
		break;
	case SPECIAL_TILE::EXIT_TILE:
		std::cout << "exit";
		break;
	}
}
