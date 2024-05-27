#ifndef CELL_H
#define CELL_H

/// <summary>
/// The state of a cell can be TREE, EMPTY, FIRE, and BOARDER.
/// </summary>

enum C_State
{
	EMPTY = 0,
	TREE = 1,
	FIRE = 2,
	BORDER = 3
};

/// <summary>
/// Contains the position and state of a Cell.
/// </summary>

class Cell
{
private:
	
	int x;
	int y;
	C_State state;

public:
	
	//Constructors
	
	explicit Cell(); //empty
	explicit Cell(const int x, const int y, const C_State state); //position x, y, and state
	
	//Getters
	
	int get_X() const; //get x position
	int get_Y() const; //get y position
	C_State get_State() const; //get state out of enumeration
	
	//Setters
	
	void set_X(const int x); //set x position
	void set_Y(const int y); //set y position
	void set_State(const C_State state); //set state from enumeration
};
#endif
