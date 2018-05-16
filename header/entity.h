#pragma once

#include "vectors.h"
#include "sprite.h"

struct transform
{
	vector2 position;
	vector2 rotation;
};

class entity : public transform
{
	friend class world;
	private:
		sprite _sprite;

		void draw(char** matrix)
		{
			int s_w = 0;
			int s_h = 0;

			for(int i=position._y; 
					i<position._y + _sprite.get_h(); i++)
			{
				for(int j=position._x; 
						j<position._x + _sprite.get_w(); j++)
				{
					matrix[i][j] = _sprite.get_matrix()[s_h][s_w];
					s_w++;
				}
				s_w = 0;
				s_h++;
			}
		}

	public:
		entity() {}
		virtual ~entity() {}

		virtual void tick() =0;
};
