#pragma once

#include <ncurses.h>
#include <vector>

#include "world.h"

/**
 * It is important to start engine with 'run()'
 * and end it with 'terminate()'.
 * */
class engine;
class game;
typedef void (game::*key_event)();

struct key_events
{
	virtual void key_q()		=0;
	virtual void key_left()		=0;
	virtual void key_right()	=0;
	virtual void key_up()		=0;
	virtual void key_down()		=0;
	virtual void key_space()	=0;
	virtual void key_w()		=0;
	virtual void key_a()		=0;
	virtual void key_b()		=0;
	virtual void key_s()		=0;
	virtual void key_d()		=0;
	virtual void key_p()		=0;
};

class engine : public world, key_events
{
	private:
		void* _void = nullptr;
		int _max_x, _max_y;

		void process_events();
		void process_key_events(int ch);

		// framerate
		unsigned int frames = 0;
		double start_time = 0;
		double time_passed = 0;
		bool first = true;
		float fps = 0.0f;


	public:
		WINDOW* const _win_main;
		engine();
		virtual ~engine();

		void run();
		void terminate();
		virtual void update() =0;

};
