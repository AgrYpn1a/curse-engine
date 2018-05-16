#include "world.h"
#include <iostream>

world::world()
{
	// init to some default world size
	coordinates = new char*[MAX_SIZE];
	for(int i=0; i<MAX_SIZE; i++)
	{
		coordinates[i] = new char[MAX_SIZE];
	}

	for(int i=0; i<MAX_SIZE; i++)
	{
		for(int j=0; j<MAX_SIZE; j++)
		{
			coordinates[i][j] = '.';
			if(i == MAX_SIZE/2 && j == MAX_SIZE/2)
			{
				coordinates[i][j] = '#';
			}
		}
	}

	coordinates[MAX_SIZE/2][MAX_SIZE/2] = '#';
	coordinates[MAX_SIZE/2-2][MAX_SIZE/2-2] = '#';
	coordinates[MAX_SIZE/2+2][MAX_SIZE/2+4] = '#';
	coordinates[MAX_SIZE/2-5][MAX_SIZE/2+3] = '#';
	coordinates[MAX_SIZE/2+2][MAX_SIZE/2-3] = '#';
}

world::~world()
{
	for(auto e : entities)
		delete e;
	while(!entities_q.empty())
		entities_q.pop();
}

vector2& world::transform_pos_to_matrix(int& x, int& y)
{
	vector2* vec = new vector2();
	vec->_x = MAX_SIZE / 2 + x; 
	vec->_y = MAX_SIZE / 2 + y; 

	return *vec;
}

void world::render()
{
	for(auto e : entities)
	{
		e->tick();		
	}
}

void world::tick()
{
	// spawn entities
	while(!entities_q.empty())
	{
		entities.push_back(entities_q.front());
		entities_q.pop();
	}

	render();
}

void world::spawn_entity(entity* e)
{
	entities_q.emplace(e);
}
