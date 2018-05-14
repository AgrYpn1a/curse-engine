#pragma once

#include <ncurses.h>

/**
 * It is important to start engine with 'run()'
 * and end it with 'terminate()'.
 * */
class engine;
class game;
typedef void (game::*key_event)();

struct key_events
{
	virtual void key_q() =0;
};

class engine : key_events
{
	private:
		void* _void = nullptr;
		int _max_x, _max_y;
		WINDOW* const _win_main;

		void process_events();
		void process_key_events(int ch);

	public:
		engine();
		~engine();

		void run();
		void terminate();
		virtual void update() =0;

};
