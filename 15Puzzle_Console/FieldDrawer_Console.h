#pragma once
#include "Field.h"

namespace Puzzle15{
	using namespace Puzzle15;

	class FieldDrawer_Console :
		public FieldDrawer
	{
	public:
		FieldDrawer_Console(std::shared_ptr<Field> sp_field);
		~FieldDrawer_Console();
		void Draw();
	};
}


