#include "GLUTCallbackFunk.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include "includeopencv.h"
#include <memory>
#include "Field.h"
#include "FieldDrawer_freeglut.h"
#include <iostream>

using namespace Puzzle15;

static int sg_winWidth;
static int sg_winHeight;
std::shared_ptr<Field> sg_field;
std::shared_ptr<FieldDrawer> sg_fieldDrawer;


void myinit()
{
	InitTexture();
	sg_field = std::make_shared<Field>();
	sg_fieldDrawer = std::make_shared<FieldDrawer_freeglut>(sg_field);
	sg_field->Shuffle();
}

void InitTexture()
{
	cv::Mat_<cv::Vec3b> img = cv::imread("numtile.bmp");

	const int texHeight = img.rows;
	const int texWidth = img.cols;

	std::vector<GLubyte> texture(texHeight * texWidth * 3);
	for (int i = 0; i < texHeight; i++){
		for (int j = 0; j < texWidth; j++){
			texture[i*texWidth * 3 + j * 3 + 0] = img(i, j)[2];
			texture[i*texWidth * 3 + j * 3 + 1] = img(i, j)[1];
			texture[i*texWidth * 3 + j * 3 + 2] = img(i, j)[0];
		}
	}


	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, texture.data());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

namespace GLUTCallbackFunk{
	const int Z_NEAR = 500;
	const int Z_FAR = -500;

	int SetUpGLUT(int* argc, char* argv[], int winWidth, int winHeight, std::string winTitle){
		//GULTの初期化
		glutInit(argc, argv);
		//ディスプレイの作成
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
		int ret = glutCreateWindow(winTitle.c_str());	//文字列はウィンドウのタイトルになる
		glutReshapeWindow(winWidth, winHeight);
		sg_winWidth = winWidth;
		sg_winHeight = winHeight;
		glutDisplayFunc(GLUTCallbackFunk::display);	//引数は関数名前
		glutKeyboardFunc(GLUTCallbackFunk::keyboard);
		glutReshapeFunc(GLUTCallbackFunk::resize);
		glutSpecialFunc(GLUTCallbackFunk::specialkeybord);
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f); //画面を塗りつぶす時の色設定
		
		return ret;
	}


	void display(){
		glClear(GL_COLOR_BUFFER_BIT);
		glEnable(GL_TEXTURE_2D);

		//>>>>ここに描画処理を書く<<<<

		sg_fieldDrawer->Draw();

		//>>>>ここまで<<<<
		glutSwapBuffers();
	}


	void keyboard(unsigned char key, int x, int y){
		switch (key){
		//	//キーボードによる回転の設定
		//case 'h':
		//	glRotated(10, 0.0, 1.0, 0.0);
		//	break;
		//case 'j':
		//	glRotated(10, 1.0, 0.0, 0.0);
		//	break;
		//case 'k':
		//	glRotated(10, -1.0, 0.0, 0.0);
		//	break;
		//case 'l':
		//	glRotated(10, 0.0, -1.0, 0.0);
		//	break;

			//終了キーボード
		case 'q':
		case 'Q':
		case '\033':
			exit(0);	//終了
			break;
		default:
			break;
		}
		glutPostRedisplay();
	}

	void specialkeybord(int key, int x, int y)
	{
		static bool s_flagContinue = true;
		if (!s_flagContinue){
			return;
		}

		switch (key)
		{
		case GLUT_KEY_LEFT:
			sg_field->MoveLeftToBlank();
			break;
		case GLUT_KEY_RIGHT:
			sg_field->MoveRightToBlank();
			break;
		case GLUT_KEY_UP:
			sg_field->MoveUpToBlank();
			break;
		case GLUT_KEY_DOWN:
			sg_field->MoveDownToBlank();
			break;
		default:
			break;
		}
		glutPostRedisplay();
		s_flagContinue = !sg_field->CheckComplete();
	}


	void resize(int w, int h){
		//ビューポートの設定
		glViewport(0, 0, w, h);

		//描画座標範囲の設定
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		const float aspect = (float)w / (float)h;
		if (aspect > 1.0){
			glOrtho(-aspect, aspect, -1.0, 1.0, Z_NEAR, Z_FAR);
			//glFrustum(-aspect, aspect, -1.0, 1.0, 2.8, 10.0);
			//gluLookAt(0.0, 0.0, 6.0, 0, 0, 0, 0, 1, 0);
		}
		else{
			glOrtho(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect, Z_NEAR, Z_FAR);
			//glFrustum(-1.0, 1.0, -1.0/aspect, 1.0/aspect, 2.8, 10.0);
			//gluLookAt(0.0, 0.0, 6.0, 0, 0, 0, 0, 1, 0);
		}

		glMatrixMode(GL_MODELVIEW);
	}



}
