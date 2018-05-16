#pragma once

class viewport
{
	public:
		unsigned int _top_x, _top_y;
		unsigned int _bot_x, _bot_y;

		viewport(unsigned int top_x, unsigned int top_y,
				unsigned int bot_x, unsigned int bot_y);
		~viewport();

};
