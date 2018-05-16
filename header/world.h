#pragma once

#include <vector>
#include <queue>

#include "entity.h"

class world
{
	protected:
		std::vector<entity*> entities;
		std::queue<entity*> entities_q;

		void render();

		char** coordinates;
	public:
		const int MAX_SIZE = 1000;

		world();
		~world();

		void tick();
		void spawn_entity(entity*);
		vector2& transform_pos_to_matrix(int&, int&);
		char** get_matrix() const { return coordinates; }


};
