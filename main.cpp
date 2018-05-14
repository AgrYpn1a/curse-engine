#include <iostream>

#include "engine.h"

class game : public engine
{
	public:
		game() {}
		~game() {}

		void update() override
		{

		}

		void key_q() override
		{
			terminate();
		}

};

int main()
{
	game g;
	g.run();

	return 0;
}
