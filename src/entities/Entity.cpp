#include "Entity.h"

#include <iostream>

#include "../graphics/Window.h"

#include "../areas/Mesh.h"

void Entity::update(Mesh& m)
{
	updatePosition(m);
}

void Entity::updatePosition(Mesh& m)
{	
	bool collision{ false };
	
	isColliding(m, collision);
	
	if (!collision)
	{
		this->model.xPos += xVel;
		this->model.yPos += yVel;
	}

	this->xVel = 0;
	this->yVel = 0;
}

void Entity::move(int xVel, int yVel)
{
	this->xVel = xVel;
	this->yVel = yVel;
}

void Entity::isColliding(Mesh& m, bool& c)
{
	const int& w = this->model.sprite->width;
	const int& h = this->model.sprite->height;

	const int& x = this->model.xPos + this->xVel;
	const int& y = this->model.yPos + this->yVel;

	const int& mw = m.sprite->width;
	const int& mh = m.sprite->height;

	const int yint{ (y * mw) };

	if (x < 0 || x + w > mw || y < 0 || y + h > mh)	// if out of bounds of area
		c = true;
	else
		for (int i = 0; i < w * h && !(c); ++i)
		{
			// iterate through the sprite of this entity to see which of its solid tiles over lap with where it will be going in the map/mesh
			int indexChecking{ yint + x + ((i / w) * mw) + (i % w) };	// formula is pretty confusing, but is just a translation to the x and y position of the entity in the actual world/map/mesh

			if (this->model.sprite->texture[i].solid && m.sprite->texture[indexChecking].solid)
				c = true;
		}
}

void Entity::render(Window& w)
{
	w.render(&model);
}
