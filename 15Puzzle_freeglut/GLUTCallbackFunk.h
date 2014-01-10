#pragma once

#include <vector>
#include <string>
#include <GL/freeglut.h>

namespace GLUTCallbackFunk{
	int SetUpGLUT(int* argc, char* argv[], int winWidth = 600, int winHeight = 600, std::string winTitle = "Window");
	void display();
	void keyboard(unsigned char key, int x, int y);
	void resize(int w, int h);
	void specialkeybord(int key, int x, int y);
}

void myinit();
void InitTexture();