#pragma once

#include <Windows.h>

class Drawable;	// remove this once I make a drawble class

class Window
{
public:
	static constexpr int WINDOW_WIDTH{ 50 };
	static constexpr int WINDOW_HEIGHT{ 10 };

	char screen[WINDOW_HEIGHT][WINDOW_WIDTH];

public:
	void clear();			// removes everything from the window
	void draw();			// prints final contents of the window
	void render(Drawable* s);	// adds sprites to the window

	void moveTo(int x, int y);	// moves terminal cursor
};