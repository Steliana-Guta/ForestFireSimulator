#include "Neighbour.h"
#include <vector>

//Constructors

Neighbour::Neighbour() //first 15 iterations will always start with NORTH direction
{
	spreading = NORTH;
}

Neighbour::Neighbour(const Spreading& spreading) //change direction each iteration after the first one
{
	this->spreading = spreading;
}

//Get and return direction

Spreading Neighbour::get_Neighbour() const //return direction
{
	return spreading;
}

Spreading Neighbour::get_Neighbour(const int index) const //randomly get new direction
{
	switch (index)
	{
	case 1:	return NORTH;
	case 2: return WEST;
	case 3: return SOUTH;
	case 4: return EAST;
	default: return NORTH;
	}
}

//Setters

void Neighbour::set_Neighbour(const Spreading& spreading) //set new direction
{
	this->spreading = spreading;
}

//Cells affected

vector<Cell> Neighbour::neighbour(const Cell& cell, const Grid& grid) //due to direction which cells will have a possibility to catch fire
{
	vector<Cell> neighbours(3);
	
	switch (spreading)
	{
	case NORTH: //cell on top and top corners
		neighbours[0] = grid.get_Cell(cell.get_X() - 1, cell.get_Y() - 1);
		neighbours[1] = grid.get_Cell(cell.get_X() - 1, cell.get_Y());
		neighbours[2] = grid.get_Cell(cell.get_X() - 1, cell.get_Y() + 1);
		return neighbours;
	case EAST: //cell on right and corner rights
		neighbours[0] = grid.get_Cell(cell.get_X() - 1, cell.get_Y() + 1);
		neighbours[1] = grid.get_Cell(cell.get_X(), cell.get_Y() + 1);
		neighbours[2] = grid.get_Cell(cell.get_X() + 1, cell.get_Y() + 1);
		return neighbours;
	case SOUTH: //cell on bottom and bottom corners
		neighbours[0] = grid.get_Cell(cell.get_X() + 1, cell.get_Y() + 1);
		neighbours[1] = grid.get_Cell(cell.get_X() + 1, cell.get_Y());
		neighbours[2] = grid.get_Cell(cell.get_X() + 1, cell.get_Y() - 1);
		return neighbours;
	case WEST: //cell on left and corner left
		neighbours[0] = grid.get_Cell(cell.get_X() + 1, cell.get_Y() - 1);
		neighbours[1] = grid.get_Cell(cell.get_X(), cell.get_Y() - 1);
		neighbours[2] = grid.get_Cell(cell.get_X() - 1, cell.get_Y() - 1);
		return neighbours;
	}
	return neighbours;	
	
}