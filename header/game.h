#pragma once

#include "engine.h"

class game : public engine
{
	public:
		game();
		~game();

		void add_camera();

	private:
		class camera* _camera = nullptr;
		virtual void update() override;

		virtual	void key_q() override;
		virtual void key_left() override;
		virtual void key_right() override;
		virtual void key_up() override;
		virtual void key_down() override;
		virtual void key_space() override;
		virtual void key_w() override;
		virtual void key_a() override;
		virtual void key_b() override;
		virtual void key_s() override;
		virtual void key_d() override;
		virtual void key_p() override;
};
