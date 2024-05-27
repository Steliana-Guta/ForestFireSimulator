#include "Grid.h"

using namespace std;

//Constructors

Grid::Grid()
{
	row_Size = 21;
	col_Size = 21;
	resize_Grid(row_Size, col_Size);
}
Grid::Grid(const int row, const int col)
{
	row_Size = row;
	col_Size = col;
	resize_Grid(row_Size, col_Size);
}

//Getters

int Grid::get_RowSize(void) const
{
	return row_Size;
}

int Grid::get_ColSize(void) const
{
	return col_Size;
}

Cell Grid::get_Cell(const int x, const int y) const
{
	return grid[x][y];
}

//Setters

void Grid::set_Cell(const Cell& cell)
{
	grid[cell.get_X()][cell.get_Y()] = cell;
}

//Resizing

void Grid::resize_Grid(const int rows, const int columns)
{
	row_Size = rows;
	col_Size = columns;
	grid.resize(row_Size, vector<Cell>(col_Size));
}
