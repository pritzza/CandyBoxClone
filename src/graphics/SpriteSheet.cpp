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

int SpriteSheet::loadPlayerSprite()
{
    const char txt[] = { 'o', ' ', 'o', ' ',
                                ' ', ' ', '>', ' ',
                                ' ', '_', '_', '_' };

    const int w{ 4 };
    const int h{ 3 };
    const int id{ SPRITE::PLAYER_SPRITE };
    SpriteTexture* p = new SpriteTexture{ w, h, id };

    for (int i = 0; i < p->texture.size(); ++i)
        p->texture[i] = txt[i];

    this->addSprite(p->id, p);
    return p->id;
}

int SpriteSheet::loadMainTabSprite()
{
    const char txt[] = { '|', ' ', 'T', 'h', 'e', ' ', ' ', '|',
                                '|', ' ', 'M', 'a', 'i', 'n', ' ', '|',
                                '|', ' ', ' ', 'T', 'a', 'b', ' ', '|', };

    const int w{ 8 };
    const int h{ 3 };
    const int id{ SPRITE::MAIN_TAB_SPRITE };
    SpriteTexture* mt = new SpriteTexture{ w, h, id };

    for (int i = 0; i < mt->texture.size(); ++i)
        mt->texture[i] = txt[i];

    this->addSprite(mt->id, mt);
    return mt->id;
}

int SpriteSheet::loadOtherTabSprite()
{
    const char txt[] = { ' ', 'O', 't', 'h', 'e', 'r', ' ', '|',
                                ' ', ' ', 'T', 'a', 'b', ' ', ' ', '|',
                                ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', };

    const int w{ 8 };
    const int h{ 3 };
    const int id{ SPRITE::OTHER_TAB_SPRITE };
    SpriteTexture* ot = new SpriteTexture{ w, h, id };

    for (int i = 0; i < ot->texture.size(); ++i)
        ot->texture[i] = txt[i];

    this->addSprite(ot->id, ot);
    return ot->id;
}

int SpriteSheet::loadLastTabSprite()
{
    const char txt[] = { ' ', 'L', 'a', 's', 't', ' ', '|',
                                ' ', ' ', 'T', 'a', 'b', ' ', '|',
                                ' ', ' ', ' ', ' ', ' ', ' ', '|', };

    const int w{ 7 };
    const int h{ 3 };
    const int id{ SPRITE::LAST_TAB_SPRITE };
    SpriteTexture* lt = new SpriteTexture{ w, h, id };

    for (int i = 0; i < lt->texture.size(); ++i)
        lt->texture[i] = txt[i];

    this->addSprite(lt->id, lt);
    return lt->id;
}

int SpriteSheet::loadCandiesCounterSprite()
{
    const char txt[] = { 'C' }; // just some dummy/placeholder text. Should always be overwritten

    const int w{ 1 };
    const int h{ 1 };
    const int id{ SPRITE::CANDIES_COUNTER_SPRITE };
    SpriteTexture* ct = new SpriteTexture{ w, h, id };

    for (int i = 0; i < ct->texture.size(); ++i)
        ct->texture[i] = txt[i];

    this->addSprite(ct->id, ct);
    return ct->id;
}

int SpriteSheet::loadLollipopsCounterSprite()
{
    const char txt[] = { 'L' }; // just some dummy/placeholder text. Should always be overwritten

    const int w{ 1 };
    const int h{ 1 };
    const int id{ SPRITE::LOLLIPOPS_COUNTER_SPRITE };
    SpriteTexture* lt = new SpriteTexture{ w, h, id };

    for (int i = 0; i < lt->texture.size(); ++i)
        lt->texture[i] = txt[i];

    this->addSprite(lt->id, lt);
    return lt->id;
}
