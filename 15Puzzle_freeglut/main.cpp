#include <iostream>
#include "GLUTCallbackFunk.h"

int main(int argc, char* argv[]){
	GLUTCallbackFunk::SetUpGLUT(&argc, argv);
	myinit();
	glutMainLoop();
	return 0;
}