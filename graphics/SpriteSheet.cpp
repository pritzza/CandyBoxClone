#include "SpriteSheet.h"

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
    return sprites.at(id);
}

void SpriteSheet::addSprite(int id, SpriteTexture* sprite)
{
    this->sprites.emplace(id, sprite);
}

int SpriteSheet::loadPlayerSprite()
{
    static const char txt[] = { 'o', ' ', 'o', ' ',
                                ' ', ' ', '>', ' ',
                                ' ', '_', '_', '_' };

    const int w{ 4 };
    const int h{ 3 };
    const int id{ SPRITE::PLAYER };
    SpriteTexture* p = new SpriteTexture{ w, h, id };

    for (int i = 0; i < p->texture.size(); ++i)
        p->texture[i] = txt[i];

    this->addSprite(p->id, p);
    return p->id;
}

int SpriteSheet::loadMainTabSprite()
{
    static const char txt[] = { '|', ' ', 'T', 'h', 'e', ' ', ' ', '|',
                                '|', ' ', 'M', 'a', 'i', 'n', ' ', '|',
                                '|', ' ', ' ', 'T', 'a', 'b', ' ', '|', };

    const int w{ 8 };
    const int h{ 3 };
    const int id{ SPRITE::MAIN_TAB_not_a_solution };
    SpriteTexture* mt = new SpriteTexture{ w, h, id };

    for (int i = 0; i < mt->texture.size(); ++i)
        mt->texture[i] = txt[i];

    this->addSprite(mt->id, mt);
    return mt->id;
}

int SpriteSheet::loadOtherTabSprite()
{
    static const char txt[] = { ' ', 'O', 't', 'h', 'e', 'r', ' ', '|',
                                ' ', ' ', 'T', 'a', 'b', ' ', ' ', '|',
                                ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', };

    const int w{ 8 };
    const int h{ 3 };
    const int id{ SPRITE::OTHER_TAB };
    SpriteTexture* ot = new SpriteTexture{ w, h, id };

    for (int i = 0; i < ot->texture.size(); ++i)
        ot->texture[i] = txt[i];

    this->addSprite(ot->id, ot);
    return ot->id;
}

int SpriteSheet::loadLastTabSprite()
{
    static const char txt[] = { ' ', 'L', 'a', 's', 't', ' ', '|',
                                ' ', ' ', 'T', 'a', 'b', ' ', '|',
                                ' ', ' ', ' ', ' ', ' ', ' ', '|', };

    const int w{ 7 };
    const int h{ 3 };
    const int id{ SPRITE::LAST_TAB };
    SpriteTexture* lt = new SpriteTexture{ w, h, id };

    for (int i = 0; i < lt->texture.size(); ++i)
        lt->texture[i] = txt[i];

    this->addSprite(lt->id, lt);
    return lt->id;
}
