#include "SpriteSheet.h"

#include "../entities/Entity.h"

SpriteSheet::SpriteSheet()
{
}

SpriteTexture* SpriteSheet::getSprite(int id)
{
    return &sprites.at(id);
}

void SpriteSheet::addSprite(int id, SpriteTexture&& sprite)
{
    this->sprites.emplace(id, std::move(sprite));
}

int SpriteSheet::loadPlayerSprite()
{
    static const char txt[] = { 'o', ' ', 'o', ' ',
                                ' ', ' ', '>', ' ',
                                ' ', '_', '_', '_' };

    SpriteTexture p{ 4, 3, 0 };
    std::memcpy(p.texture.get(), txt, sizeof(txt));
    this->addSprite(p.id, std::move(p));
    return p.id;
}

int SpriteSheet::loadMainTabSprite()
{
    static const char txt[] = { '|', ' ', 'T', 'h', 'e', ' ', ' ', '|',       //{ '0' };
                                '|', ' ', 'M', 'a', 'i', 'n', ' ', '|',
                                '|', ' ', ' ', 'T', 'a', 'b', ' ', '|', };

    SpriteTexture mt{ 8, 3, 1 };
    //SpriteTexture mt{ 1, 1, 1 };
    std::memcpy(mt.texture.get(), txt, sizeof(txt));
    this->addSprite(mt.id, std::move(mt));
    return mt.id;
}
