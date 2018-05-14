#pragma once

#include <ncurses.h>

class engine
{
	private:
		void* _void = nullptr;
		int _max_x, _max_y;
		WINDOW* const _win_main;

	public:
		engine();
		~engine();

		void run();
};
