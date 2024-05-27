#ifndef NEIGHBOUR_H
#define NEIGHBOUR_H

#include "Cell.h"
#include "Grid.h"

#include<vector>

using namespace std;

/// <summary>
/// Enumeration of compass directions
/// </summary>

enum Spreading
{
	NORTH = 0,
	WEST = 1,
	SOUTH = 2,
	EAST = 3
};

/// <summary>
/// Selectiong cells around the fire cell to spread fire to.
/// </summary>

class Neighbour
{
private:

	Spreading spreading; 

public:

	//Constructors
	
	Neighbour();
	Neighbour(const Spreading& spreading);

	//Get and return direction
	
	Spreading get_Neighbour()	const;
	Spreading get_Neighbour(const int index) const;

	//Setter
	
	void set_Neighbour(const Spreading& spreading);

	//Cells affected
	
	vector<Cell> neighbour(const Cell& cell, const Grid& grid);
};

#endif
