#pragma once
#include <ncurses.h>
#include "entity.h"

class camera : public entity
{
	private:
		class world*  _world;
		class viewport* const _viewport;
		WINDOW* const _win;

	public:
		camera(class world*, class viewport* const, WINDOW* const);
		~camera();

		virtual void tick() override;

		void render();
		
		// move etc..
};
