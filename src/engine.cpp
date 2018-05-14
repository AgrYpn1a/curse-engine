#include "engine.h"
#include "stdlib.h"

engine::engine() :
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
		process_events();
		update();
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
		default:
			break;
	}
}
