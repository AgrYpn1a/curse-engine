#include "viewport.h"

viewport::viewport(unsigned int top_x, unsigned int top_y,
		unsigned int bot_x, unsigned int bot_y) :
	_top_x{top_x},
	_top_y{top_y},
	_bot_x{bot_x},
	_bot_y{bot_y} {}

viewport::~viewport() {}
