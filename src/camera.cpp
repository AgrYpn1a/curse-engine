#include "camera.h"
#include "world.h"
#include "viewport.h"

#include <iostream>

camera::camera(world* __world, 
		viewport* const __viewport,
		WINDOW* const __win) :
	_world{__world},
	_viewport{__viewport},
	_win{__win} {}

camera::~camera()
{
}

void camera::tick()
{
	render();
}

void camera::render()
{
	vector2 mat_coord = 
		_world->transform_pos_to_matrix(position._x, position._y);

	// screen coordinates
	int start_x = _viewport->_top_x;
	int end_x = _viewport->_bot_x;
	int start_y = _viewport->_top_y;
	int end_y = _viewport->_bot_y;

	// matrix coordinates
	int curr_x = mat_coord._x - (end_x/2);
	int curr_y = mat_coord._y + (end_y/2);

	wmove(_win, start_y, start_x);

	for(int i=start_y; i<end_y; i++)
	{
		for(int j=start_x; j<end_x; j++)
		{
			char c = _world->get_matrix()[curr_y - i][curr_x + j];
			wprintw(_win, "%c", c);
		}


		wmove(_win, start_y + i, start_x);
	}

	wrefresh(_win);
}

