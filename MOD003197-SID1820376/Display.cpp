#include "Display.h"

//Constructors

Display::Display()
{
	neighbour = Neighbour();
	burnChance = 0.5f;
	regeneration = 0.05f;
	frame = 0;
}

//Grid life

void Display::create_grid() //setting borders and trees
{
	//get size of grid
	int rowSize = grid.get_RowSize();
	int colSize = grid.get_ColSize();

	for (int x = 0; x < rowSize; x++)
	{
		for (int y = 0; y < colSize; y++)
		{
			if (x == 0 || x == rowSize - 1) grid.set_Cell(Cell(x, y, BORDER)); //creating border on top row and bottom row
			else if (y == 0 || y == colSize - 1) grid.set_Cell(Cell(x, y, BORDER)); //creating border on first column and last column
			else grid.set_Cell(Cell(x, y, TREE)); //the rest are set to trees
		}
	}
	grid.set_Cell(Cell(10, 10, FIRE)); //start fire at center position
}

void Display::update_grid()
{
	frame = update_frame(frame); //update frame to change wind direction after 15 stages
	if (all_Trees()) fire(); //if there is no fire in the forest ignite at random

	for (int x = 1; x < grid.get_RowSize() - 1; x++)
	{
		for (int y = 1; y < grid.get_ColSize() - 1; y++)
		{
			Cell cell = grid.get_Cell(x, y);
			// http://www.cplusplus.com/reference/vector/vector/push_back/ add elements to a vector
			if (cell.get_State() == FIRE) fire_Cell.push_back(cell); //if cell on fire add to fire_Cell vector list
			else if (cell.get_State() == EMPTY) empty_Cell.push_back(cell); //if cell empty add to empty_Cell vector list
		}
	}

	spread(fire_Cell); //spread fire
	regrowth(empty_Cell); //regenerate trees
	fire_Cell.clear(); //make sure each frame only the fire cells are on this list
	empty_Cell.clear(); //make sure each frame only empty cells are on this list
}

void Display::set_grid(const Grid& grid)
{
	this->grid = grid;
}

//Fire direction

void Display::spread_direction()
{
	random = rand() % 4 + 1;  //randomly chooses out of NORTH SOUTH WEST EAST
	Spreading spreading = neighbour.get_Neighbour(random); //spreading to neighbouring cells
	set_direction(spreading); //set compass direction
}

void Display::set_direction(const Spreading& spreading)
{
	this->neighbour.set_Neighbour(spreading); //considering direction select neighbours that will catch fire
}

//Getters

Spreading Display::get_direction() const
{
	return neighbour.get_Neighbour(); //return compass direction
}

Grid Display::get_Grid() const
{
	return grid;
}

//Frames

int Display::update_frame(int count)
{
	bool enable = false;
	if (count == 15) //every 15 frames change wind direction
	{
		spread_direction();
		count = 0; //restart counting each iteration
	}
	count++; //count iteration each turn
	return count;
}

int Display::frames() const
{
	return frame; 
}

//Private

bool Display::all_Trees()  //check if all trees are intact at start
{
	bool all_t = true;
	
	for (int x = 1; x < grid.get_RowSize() - 1; x++)
	{
		for (int y = 1; y < grid.get_ColSize() - 1; y++)
		{
			Cell cell = grid.get_Cell(x, y);
			if (cell.get_State() == FIRE) all_t = false;
		}
	}
	return all_t;
}
void Display::spread(const vector<Cell>& cellList)
{
	Cell fire_c;
	vector<Cell> cell_v;
	
	for (int i = 0; i < cellList.size(); i++)
	{
		fire_c = cellList[i]; //list of cells on fire
		cell_v = neighbour.neighbour(fire_c, grid); //set neighbour cells on fire

		for (int j = 0; j < cell_v.size(); j++)
		{
			Cell cell = cell_v[j];
			random = rand() % 50 + 1;  //50% chance to catch fire

			if (cell.get_State() == TREE && random < (burnChance * 50)) cell.set_State(FIRE); // set 50% chance to catch fire as a neighbour cell
			grid.set_Cell(cell); //update grid next iteration
		}

		fire_c.set_State(EMPTY); //each fire cell becomes empty after iteration
		grid.set_Cell(fire_c); //update grid next iteration
	}
}

void Display::regrowth(const vector<Cell>& cellList)
{
	Cell cell_new;

	for (int i = 0; i < cellList.size(); i++)
	{
		cell_new = cellList[i];
		random = rand() % 100 + 1; //100% to regrow at some point 

		if (random < (regeneration * 100)) cell_new.set_State(TREE); //100% chance to regrow after the regeneration period
		grid.set_Cell(cell_new); //update grid next iteration
	}
}

void Display::fire() //when fire dies down reignite at random locations
{
	for (int i = 0; i < 20; i++)
	{
		int x = random = rand() % 20 + 1; //random x location
		int y = random = rand() % 20 + 1; //random y location

		Cell cell = grid.get_Cell(x, y); //get cells
		if (cell.get_State() == TREE) cell.set_State(FIRE); //set cells on fire
		grid.set_Cell(cell); //update grid next iteration
	}
}
