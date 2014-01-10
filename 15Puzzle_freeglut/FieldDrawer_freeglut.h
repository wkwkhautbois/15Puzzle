#pragma once
#include "Field.h"
#include <Windows.h>
#include <GL/GL.h>

namespace Puzzle15{
	using namespace Puzzle15;
	class FieldDrawer_freeglut :
		public FieldDrawer
	{
	private:
		GLdouble _left;
		GLdouble _right;
		GLdouble _top;
		GLdouble _bottom;

	public:
		FieldDrawer_freeglut(std::shared_ptr<Field> sp_field);
		~FieldDrawer_freeglut();
		void Draw();
	};

}