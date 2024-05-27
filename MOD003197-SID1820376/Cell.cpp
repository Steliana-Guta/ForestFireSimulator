#include "Cell.h"
#include <iostream>

using namespace std;

//Constructors

Cell::Cell()
{
	x = 0;
	y = 0;
	state = EMPTY;
}
Cell::Cell(const int x, const int y, const C_State state)
{
	this->x = x;
	this->y = y;
	this->state = state;
}

//Getters

int Cell::get_X() const
{
	return x;
}
int Cell::get_Y() const
{
	return y;
}
C_State Cell::get_State() const
{
	return state;
}

//Setters

void Cell::set_X(const int x)
{
	this->x = x;
}
void Cell::set_Y(const int y)
{
	this->y = y;
}
void Cell::set_State(const C_State state)
{
	this->state = state;
}
