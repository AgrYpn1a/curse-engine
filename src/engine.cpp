#include <chrono>
#include <stdlib.h>

#include "engine.h"

engine::engine() :
	world(),
	_void {initscr()},
	_max_x{getmaxx(stdscr)},
	_max_y{getmaxy(stdscr)},
	_win_main{newwin(_max_y-1, _max_x-1, 1, 1)}
{
	curs_set(0);
	noecho();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	refresh();

	box(_win_main, 0, 0);
	wrefresh(_win_main);

	start_time = time_passed;
}

engine::~engine()
{
	endwin();
}

void engine::run()
{
	// engine loop
	while(true)
	{
		world::tick();
		process_events();
		update();

		for(auto e : entities)
			e->tick();
	}
}

void engine::terminate()
{
	endwin();
	exit(0);
}

void engine::process_events()
{
	process_key_events(getch());
}

void engine::process_key_events(int ch)
{
	if(ch == ERR) return;

	// process key inputs
	switch(ch)
	{
		case 'q':
			this->key_q();
			break;
		case KEY_LEFT:
			this->key_left();
			break;
		case KEY_UP:
			this->key_up();
			break;
		case KEY_DOWN:
			this->key_down();
			break;
		case KEY_RIGHT:
			this->key_right();
			break;
		default:
			break;
	}
}
