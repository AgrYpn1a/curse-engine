#include "game.h"
#include "camera.h"
#include "viewport.h"

class player : public entity
{
	public:
		player() {}
		~player() {}

		void tick() override
		{
		}
};

game::game()
{
	spawn_entity(new player());
}

game::~game()
{

}


void game::update()
{
	tick();
}

void game::add_camera()
{
	viewport* const v = new viewport(1, 1, 30, 10);
	camera* c = new camera(this,v, _win_main);
	_camera = c;
	spawn_entity(c);
}

void game::key_q()
{
	terminate();
}

void game::key_left() 
{
	_camera->position = _camera->position + vector2(-1, 0);
}

void game::key_right()
{
	_camera->position = _camera->position + vector2(1, 0);
}

void game::key_up() 
{
	_camera->position = _camera->position + vector2(0, 1);
}

void game::key_down() 
{
	_camera->position = _camera->position + vector2(0, -1);
}

void game::key_space() {}
void game::key_w() {}
void game::key_a() {}
void game::key_b() {}
void game::key_s() {}
void game::key_d() {}
void game::key_p() {}
