#include "SpriteSheet.h"

#include <fstream>
#include <string>

SpriteSheet::~SpriteSheet()
{
    terminate();
}

void SpriteSheet::terminate()
{
    for (auto it = sprites.begin(); it != sprites.end(); ++it)
        delete it->second;
}

SpriteTexture* SpriteSheet::getSprite(int id)
{
    // return null ptr if cant find sprite
    if (this->sprites.find(id) == sprites.end())
        return nullptr;

    return sprites.at(id);
}

void SpriteSheet::addSprite(int id, SpriteTexture* sprite)
{
    // only add sprite if its not already loaded
    if (this->sprites.find(id) == sprites.end())
        this->sprites.emplace(id, sprite);
}

void SpriteSheet::removeSprite(int id)
{
}

int SpriteSheet::loadSprite(const int id)
{
    //std::string fileName{ "res/sprites/" };

    switch (id)
    {
    case SPRITE::PLAYER_SPRITE:
        loadFromFile("res/sprites/player.txt", id);
        break;
    case SPRITE::PLAYER_FACE_SPRITE:
        loadFromFile("res/sprites/player face.txt", id);
        break;
    case SPRITE::MAIN_TAB_SPRITE:
        loadFromFile("res/sprites/tabs/main tab.txt", id);
        break;
    case SPRITE::OTHER_TAB_SPRITE:
        loadFromFile("res/sprites/tabs/other tab.txt", id);
        break;
    case SPRITE::LAST_TAB_SPRITE:
        loadFromFile("res/sprites/tabs/last tab.txt", id);
        break;
    case SPRITE::JON_SPRITE:
        loadFromFile("res/sprites/jon.txt", id);
        break;
    case SPRITE::GUY_SPRITE:
        loadFromFile("res/sprites/guy.txt", id);
        break;
    case SPRITE::CANDIES_COUNTER_SPRITE:        // these are actually text sprites, which are modified during runtime, so it doesnt really matter what they are cause they change
    case SPRITE::LOLLIPOPS_COUNTER_SPRITE:
        loadFromFile("res/sprites/text.txt", id);
        break;
    default:
        loadFromFile("res/sprites/missing.txt", id); // load play as error
        return id;
    }

    return id;
}

void SpriteSheet::loadFromFile(const char* fileName, const int id)
{
    std::ifstream file(fileName);
    if (file)
    {
        std::string line;

        std::getline(file, line);
        const int width = std::stoi(line);
        std::getline(file, line);
        const int height = std::stoi(line);
        
        SpriteTexture* tempSprite = new SpriteTexture(width, height, id);

        for (int i = 0; i < height; ++i)
        {
            std::getline(file, line);       // iterate through all of the file's lines from top to bottom
            const int charsPerTile{ 2 };    // in the file io, it takes 2 chars to extract the data for a tile, the first being its ascii symbol then solidity

            for (int j = 0; j < width * charsPerTile - 1; j += charsPerTile)  // iterate through each line from left to right
                tempSprite->texture[(i * width) + j/ charsPerTile].init(line.at(j), line.at(j + 1) - ' ');	// ' ' means its not solid, anything else means its solid, like '.'
        }

        addSprite(id, tempSprite);
    }
}