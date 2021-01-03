#include "Window.h"

#include <iostream>
#include <string>

#include "Drawable.h"
#include "SpriteTexture.h"

void Window::clear()
{
	const char clearChar{ '.' };

	// iterate through the map to get rid of anything from last frame
	for (int y = 0; y < WINDOW_HEIGHT; ++y)
		for (int x = 0; x < WINDOW_WIDTH; ++x)
			screen[y][x] = clearChar;
}

void Window::draw()
{
	std::string screen{};

	for (int y = 0; y < WINDOW_HEIGHT; ++y)
	{
		for (int x = 0; x < WINDOW_WIDTH; ++x)
			screen += this->screen[y][x];
		screen += '\n';
	}

	std::cout << screen;

	// reset terminal cursor back to 0,0
	this->moveTo(0, 0);
}

void Window::render(Drawable* e)
{
	if (e->sprite != nullptr)
	{
		const int& xOffset{ e->xPos };
		const int& yOffset{ e->yPos };
		const int& spriteSize{ e->sprite->width * e->sprite->height };

		for (int i = 0; i < spriteSize; ++i)
		{
			const int& y{ (i / e->sprite->width) + yOffset };
			int x{ (i % e->sprite->width) + xOffset };

			// flips texture order over y axis, eg : "../" -> "/.."
			if (e->reverse)
				x = (((spriteSize - i) - 1) % e->sprite->width) + xOffset;

			const char transparent{ '%' };	// where every this char is found, it is not an empty ' ', instead it is transparent and will show through

			if ((x >= 0 && x < WINDOW_WIDTH) && (y >= 0 && y < WINDOW_HEIGHT))	// no out of bounds
				if (e->sprite->texture[i].symbol != transparent)
					this->screen[y][x] = e->sprite->texture[i].symbol;
		}
	}
}

void Window::moveTo(int x, int y)
{
	COORD coord{ x, y};
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}