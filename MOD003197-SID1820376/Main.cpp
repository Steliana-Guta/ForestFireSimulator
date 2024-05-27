#include "Display.h"
#include "Draw.h"

#include <iostream>
#include <string>

using namespace std;
void Initiate();

int main()
{
	Initiate();
	return 0;
}

void Initiate()
{
	Grid grid = Grid(21, 21); //determine grid size
	Display display = Display(); 
	Draw draw = Draw(display);
	string input;
	bool redraw = true;

	display.set_grid(grid);
	display.create_grid();
	draw.change_size(400, 500); //set console size
	draw.display_direction(); 
	draw.diplay_frame();
	draw.display_grid(display.get_Grid());

	while (redraw) //while exit it not pressed 
	{
		cout << "Press Enter." << endl; //info for user to get to next iteration
		cout << "Press any key followed by Enter to Exit." << endl; //exit option
		getline(cin, input); //read input
		
		if (input != "" ) redraw = false; //if any key is entered break
		else
		{
			draw.clear_display();
			display.update_grid();
			draw.display_direction();
			draw.diplay_frame();
			draw.display_grid(display.get_Grid());
		}
	}
}
