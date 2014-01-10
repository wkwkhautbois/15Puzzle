#include "FieldDrawer_Console.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace Puzzle15;
namespace Puzzle15{

	FieldDrawer_Console::FieldDrawer_Console(std::shared_ptr<Field> sp_field)
		:FieldDrawer(sp_field)
	{
	}


	FieldDrawer_Console::~FieldDrawer_Console()
	{
	}

	void FieldDrawer_Console::Draw()
	{
		const int W = FIELD_W;
		const int H = FIELD_H;
		for (int i = 0; i < H; i++){
			std::stringstream ss;
			for (int j = 0; j < W; j++){
				if (_sp_field->at(i*W + j)){
					ss << std::setw(3) << std::right << _sp_field->at(i*W + j)->num();
				}else{
					ss << "   ";
				}

				//if (j != W-1) ss << ",";
			}
			std::cout << ss.str() << std::endl;
		}

	}

}