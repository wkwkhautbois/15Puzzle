#include "FieldDrawer_freeglut.h"

using namespace Puzzle15;
namespace Puzzle15{


	FieldDrawer_freeglut::FieldDrawer_freeglut(std::shared_ptr<Field> sp_field)
		:FieldDrawer(sp_field)
	{
		_left = -0.8;
		_right = 0.8;
		_top = 0.8;
		_bottom = -0.8;
	}


	FieldDrawer_freeglut::~FieldDrawer_freeglut()
	{
	}

	void FieldDrawer_freeglut::Draw()
	{
		const int W = FIELD_W;
		const int H = FIELD_H;

		const GLdouble bkWidth = (_right - _left) / W;
		const GLdouble blHeight = (_top - _bottom) / H;

		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				if (_sp_field->at(i*W + j)){
					int n = _sp_field->at(i*W + j)->num() - 1;
					int x = n % W;
					int y = n / W;
					
					glBegin(GL_QUADS);

					glTexCoord2d(1.0/W*x, 1.0/W*y);
					glVertex2d(_left + bkWidth*j, _top - blHeight*i);

					glTexCoord2d(1.0 / W*x, 1.0 / W*(y+1));
					glVertex2d(_left + bkWidth*j, _top - blHeight*(i+1));

					glTexCoord2d(1.0 / W*(x+1), 1.0 / W*(y+1));
					glVertex2d(_left + bkWidth*(j+1), _top - blHeight*(i+1));

					glTexCoord2d(1.0 / W*(x+1), 1.0 / W*y);
					glVertex2d(_left + bkWidth*(j+1), _top - blHeight*i);

					glEnd();
				}
			}
		}
	}
}