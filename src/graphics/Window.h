#pragma once

#include <Windows.h>

class Drawable;	// remove this once I make a drawble class

class Window
{
public:
	static constexpr int WINDOW_WIDTH{ 64 };
	static constexpr int WINDOW_HEIGHT{ 24 };

	char screen[WINDOW_HEIGHT][WINDOW_WIDTH];

public:
	void clear();			// removes everything from the screen
	void draw();			// prints final contents of the screen to the window of the terminal
	void render(Drawable* s);	// adds sprites to the screen/window

	void moveTo(int x, int y);	// moves terminal cursor
};