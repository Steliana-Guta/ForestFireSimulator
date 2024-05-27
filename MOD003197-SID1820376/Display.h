#ifndef DISPLAY_H
#define DISPLAY_H

#include "Cell.h"
#include "Grid.h"
#include "Neighbour.h"
#include <vector>

using namespace std;

/// <summary>
/// Creating, updating the grid and state of cell.
/// </summary>

class Display
{
private:
	
	float regeneration; //trees regrowth rate
	float burnChance; //chance neighbour cells catching fire 
	vector<Cell> fire_Cell; //cells on fire
	vector<Cell> empty_Cell; //empty cells
	int random;
	int frame; //number of frames on one wind direction

	Cell burn_direction; //wind direction
	Grid grid; 
	Neighbour neighbour; //surounding cells

	bool all_Trees();  
	void spread(const vector<Cell>& cellList); //setting fire to neighbours
	void regrowth(const vector<Cell>& cellList); //regrowing trees
	void fire(); //set fire

public:

	//Constructors
	
	Display();

	//Grid life
	
	void create_grid();
	void update_grid();
	void set_grid(const Grid& grid);
	
	//Fire direction
	
	void spread_direction();
	void set_direction(const Spreading& spreading);
	
	//Getters
	
	Grid get_Grid() const;
	Spreading get_direction() const;
	
	//Frames

	int update_frame(int count);
	int frames() const;
};

#endif
