#include "engine.h"

engine::engine() :
	_void {initscr()},
	_max_x{getmaxx(stdscr)},
	_max_y{getmaxy(stdscr)},
	_win_main{newwin(_max_y-1, _max_x-1, 1, 1)}
{
	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr, true);
	refresh();

	box(_win_main, 0, 0);
	wrefresh(_win_main);

	getch();
}

engine::~engine()
{
	endwin();
}
