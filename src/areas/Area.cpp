#include "Area.h"

#include <fstream>
#include <string>

#include "../states/State.h"
#include "../graphics/Drawable.h"
#include "../graphics/SpriteSheet.h"
#include "../graphics/SpriteTexture.h"
#include "../graphics/Window.h"

Area::~Area()
{
    delete this->map->sprite;
    delete this->map;

    // delete all sprites loaded for are, like player and other enemy/entity sprites
}

void Area::loadArea(const int id)
{
	switch (id)
	{
	case STATE::BATTLE_TEST_STATE:
		loadFromFile("res/areas/test3.txt");
        initPlayer(Drawable::spriteSheet->getSprite(Drawable::spriteSheet->loadSprite(SPRITE::GUY_SPRITE)), 0, 0);
		break;
    default:
        loadFromFile("res/areas/test.txt");
	}
}

void Area::initPlayer(SpriteTexture* s, int startingX, int startingY)
{
    player.model.sprite = s;
    player.model.xPos = startingX;
    player.model.yPos = startingY;
}

void Area::loadFromFile(const char* fileName)
{
    std::ifstream file(fileName);

    if (file)
    {
        std::string line;

        std::getline(file, line);
        const int width = std::stoi(line);
        std::getline(file, line);
        const int height = std::stoi(line);

        SpriteTexture* meshSprite = new SpriteTexture(width, height, -1);   //sprite id of area is -1, just cause all other sprites will be above 0
        Mesh* tempMesh = new Mesh(meshSprite, 0,0);     // the sprite also isnt apart of the sprite sheet

        for (int i = 0; i < height; ++i)
        {
            std::getline(file, line);   // iterate through all of the file's lines from top to bottom
            const int charsPerTile{ 3 }; // in the file io, it takes 3 chars to extract the data for a tile, the first being its ascii symbol then solidity, then type of special tile

            for (int j = 0; j < width * charsPerTile - 1; j += charsPerTile)  // iterate through each line from left to right
            {
                tempMesh->sprite->texture[(i * width) + j / charsPerTile].init(line.at(j), line.at(j + 1) - ' ');	// ' ' means its not solid, anything else means its solid, like '.'
                tempMesh->specialTiles[(i * width) + j / charsPerTile].init(j + 2);
            }
        }

        //for (int i = 0; i < width * height; ++i)
        //{
        //	if (!(i % width) && i)
        //		std::cout << std::endl;
        //
        //	std::cout << tempMesh->sprite->texture[i].symbol << tempMesh->sprite->texture[i].solid << tempMesh->specialTiles[i].type;
        //}

        this->map = tempMesh;
    }
}

void Area::render(Window& w)
{
    w.render(map);
    w.render(&player.model);

}
