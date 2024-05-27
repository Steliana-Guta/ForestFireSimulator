#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <vector>

using namespace std;

/// <summary>
/// 2D array of Cells.
/// </summary>

class Grid
{
private:
	
	int row_Size;
	int col_Size;
	vector < vector<Cell> > grid; //array of values

public:
	
	//Constructors
	
	Grid(); //empty
	Grid(const int rows, const int columns); // size constructor
	
	//Getters
	
	int get_RowSize() const; //get row number
	int get_ColSize() const; //get column number
	
	Cell get_Cell(const int x, const int y) const; //get each cell
	
	//Setters
	
	void set_Cell(const Cell& cell); //setting positions

	//Resizing

	void resize_Grid(const int row, const int col); //changing size 
};
#endif