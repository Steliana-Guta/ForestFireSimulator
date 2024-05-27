#ifndef DRAW_H
#define  DRAW_H

#include "Display.h"
#include <Windows.h>

/// <summary>
/// The colours of the elements.
/// </summary>

enum ConsoleColour
{
	GREEN = 2,
	RED = 4,
	WHITE = 7
};

/// <summary>
/// Controls the display.
/// </summary>

class Draw
{
private:
	
	Display* display;
	HANDLE consoleHandle;
	HWND hwnd;

	void diplay_state(const Cell& cell);
	
public:

	//Constructors
	
	Draw();
	Draw(Display& display);

	//Print to screen
	
	void display_grid(const Grid& grid);
	void clear_display();
	void display_direction();
	void diplay_frame();

	//Console position

	void change_size(const int width, const int height);
};

#endif
