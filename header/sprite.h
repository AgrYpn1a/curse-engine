#pragma once

class sprite
{
	private:
		char** matrix = nullptr;
		int _w, _h;

	public:
		sprite()
		{
			// init default sprite
			_w = 1;
			_h = 1;
			matrix = new char*[_h];
			matrix[0] = new char[_w];
			matrix[0][0] = '#'; // default sprite symbol

		}

		~sprite()
		{
			for(int i=0; i<_h; i++)
			{
				delete matrix[i];
			}

			delete matrix;
		}

		void load(char** matrix, int w, int h)
		{
			_w = w;
			_h = h;
			this->matrix = matrix;
		}

		char** get_matrix() const
		{	
			return matrix;
		}

		int get_w() const { return _w; }
		int get_h() const { return _h; }
};
