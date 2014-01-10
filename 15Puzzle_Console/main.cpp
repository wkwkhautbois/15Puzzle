#include <iostream>
#include <string>
#include <memory>
#include "Field.h"
#include "FieldDrawer_Console.h"

using namespace Puzzle15;

int GameMainLoop(std::shared_ptr<FieldDrawer> fieldDrawer);

int main(int argc, char* argv[]){
	std::shared_ptr<Field> field(new Field);
	std::shared_ptr<FieldDrawer> fieldDrawer = std::shared_ptr<FieldDrawer>(new FieldDrawer_Console(field));	

	field->Shuffle();
	fieldDrawer->Draw();
	GameMainLoop(fieldDrawer);

	return 0;
}

int GameMainLoop(std::shared_ptr<FieldDrawer> fieldDrawer)
{
	int count = 0;
	std::shared_ptr<Field> field = fieldDrawer->getSpField();

	bool flagContinue = true;
	while (flagContinue){
		char chin;
		std::cin >> chin;
		
		const char MOVE_KEY_DOWN = 'd';
		const char MOVE_KEY_UP = 'u';
		const char MOVE_KEY_LEFT = 'l';
		const char MOVE_KEY_RIGHT = 'r';
		switch (chin)
		{
			//TODO:
		case MOVE_KEY_DOWN:
			field->MoveDownToBlank();
			break;
		case MOVE_KEY_UP:
			field->MoveUpToBlank();
			break;
		case MOVE_KEY_LEFT:
			field->MoveLeftToBlank();
			break;
		case MOVE_KEY_RIGHT:
			field->MoveRightToBlank();
			break;
		case 'q':
		case 'Q':
			exit(0);
			break;
		default:
			break;
		}

		fieldDrawer->Draw();
		std::cout << std::endl;

		flagContinue = !(field->CheckComplete());

		
	}

	return count;
}