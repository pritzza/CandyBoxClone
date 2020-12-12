#include "TileSet.h"

#include <fstream>
#include <iostream>
#include <string>

#include "Tile.h"

TileSet::~TileSet()
{
	delete[] this->tiles;
}

void TileSet::loadTest()
{
	const char* fileName = "res/areas/test.txt";
	
	this->loadArea(fileName);
}

void TileSet::loadArea(const char* fileName)
{
	std::ifstream file(fileName);
	if (file)
	{
		std::string line;

		std::getline(file, line);
		this->width = std::stoi(line);
		std::getline(file, line);
		this->height = std::stoi(line);
		this->tiles = new Tile[width * height];

		for (int i = 0; i < width * height; ++i)
		{
			std::getline(file, line, ' ');

			if (line.length() > 2)
				line.replace(0, line.length() - 2, "");

			tiles[i].init(line.at(0), line.at(1) - '0');	// we will use 0 and 1 to determine solidity, which we can turn into a bool cause ASCII table
		}

		//for (int i = 0; i < width * height; ++i)
		//{
		//	if (!(i % width) && i)
		//		std::cout << std::endl;
		//
		//	std::cout << tiles[i].symbol << tiles[i].solid << ' ';
		//}
	}
}