#include "Draw.h"
#include <iostream>

using namespace std;

//Constructors

Draw::Draw()
{
    // https://docs.microsoft.com/en-us/windows/console/getstdhandle retrieve handle
	// https://docs.microsoft.com/en-us/windows/console/getconsolewindow retrieve window handle
	//used for changing size and position of console as well as applying colour to ASCII symbols
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	hwnd = GetConsoleWindow();
}

Draw::Draw(Display& display)
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	hwnd = GetConsoleWindow();
	this->display = &display;
}

//Console position

void Draw::change_size(const int width, const int height)
{
	// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-movewindow how to change position of console
	MoveWindow(hwnd, 0, 0, width, height, true);
}

//Print to screen

void Draw::display_grid(const Grid& grid) //print to console all cells
{
	cout << endl;
	for (int x = 0; x < grid.get_RowSize(); x++)
	{
		for (int y = 0; y < grid.get_ColSize(); y++)
		{
			diplay_state(grid.get_Cell(x, y));
		}
		cout << endl;
	}
	
}

void Draw::clear_display()
{
	// http://www.cplusplus.com/forum/beginner/18191/ no more flicker between iterations
	COORD position;
	position.X = 0;
	position.Y = 0;
	SetConsoleCursorPosition(consoleHandle, position);
}

void Draw::display_direction() //print wind direction
{
	cout << "Wind direction: ";
	switch (display->get_direction())
	{
		case NORTH:	cout << "NORTH" << endl; break;
		case WEST: cout << "WEST " << endl; break; //added extra blank space at th end to cover H on north and south
		case SOUTH:	cout << "SOUTH" << endl; break;
		case EAST: cout << "EAST " << endl; break;  //added extra blank space at th end to cover H on north and south
	}
}

void Draw::diplay_frame() //print number of frames
{
	int count = display->frames();
	cout << "Iteration: " << count << ' ' << endl;
}

//Private

void Draw::diplay_state(const Cell& cell) //print ASCII symbols for each cell and assigning colour
{
	ConsoleColour colour; //enumeration of colours and their ANSI codes

	switch (cell.get_State())
	{
	case EMPTY:
		std::cout << " "; //empty cell/ burned down cell
		break;
	case TREE:
		SetConsoleTextAttribute(consoleHandle, colour = GREEN); //setting trees to green
		std::cout << "&";
		break;
	case FIRE:
		SetConsoleTextAttribute(consoleHandle, colour = RED); //setting fire to red
		std::cout << "X";
		break;
	case BORDER:
		SetConsoleTextAttribute(consoleHandle, colour = WHITE); //setting border to white
		std::cout << "#";
		break;
	}
}