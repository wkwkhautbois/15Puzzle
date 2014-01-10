#pragma once
// �w�b�_�[�t�@�C��
#include <opencv2/opencv.hpp>

// �o�[�W�����擾
#define CV_VERSION_STR CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)

//#ifdef _WIN64
////#define CV_LIB "C:\\OpenCV\\OpenCV" CV_VERSION_STR "\\x64\\vc11\\lib\\"
//#define CV_LIB "C:\\OpenSourceLibrary\\OpenCV" CVAUX_STR(CV_MAJOR_VERSION) "." CVAUX_STR(CV_MINOR_VERSION) "."CVAUX_STR(CV_SUBMINOR_VERSION) "\\x64\\vc11\\lib\\"
//#else
////#define CV_LIB "C:\\OpenCV\\OpenCV" CV_VERSION_STR "\\x86\\vc11\\lib\\"
//#define CV_LIB "C:\\OpenSourceLibrary\\OpenCV" CVAUX_STR(CV_MAJOR_VERSION) "." CVAUX_STR(CV_MINOR_VERSION) "."CVAUX_STR(CV_SUBMINOR_VERSION) "\\x86\\vc11\\lib\\"
//#endif
#define CV_LIB ""


// �r���h���[�h
#ifdef _DEBUG
#define CV_EXT_STR "d.lib"
#else
#define CV_EXT_STR ".lib"
#endif

// ���C�u�����̃����N�i�s�v�ȕ��̓R�����g�A�E�g�j
#pragma comment(lib, CV_LIB		"opencv_core"            CV_VERSION_STR CV_EXT_STR) // �������m�ہE����A�s�񉉎Z�A�`��Ȃ�
#pragma comment(lib, CV_LIB		"opencv_highgui"        CV_VERSION_STR CV_EXT_STR) // �E�B���h�E�Ȃ�GUI�A�t�@�C���ǂݍ��݁E�ۑ��A�r�f�I�t�@�C���A�J�����Ȃ�
#pragma comment(lib, CV_LIB		"opencv_imgproc"		CV_VERSION_STR CV_EXT_STR) // �摜�����A��ʓI�ȃt�B���^�����Ȃ�
#pragma comment(lib, CV_LIB		"opencv_calib3d"		CV_VERSION_STR CV_EXT_STR) // �J�����L�����u���[�V�����A�X�e���I�J�����Ȃ�
#pragma comment(lib, CV_LIB		"opencv_gpu"			CV_VERSION_STR CV_EXT_STR) // GPU(CUDA)�ɂ��s�񉉎Z�A�摜�����Ȃ� ��ver2.2���_�ł̓���
#pragma comment(lib, CV_LIB		"opencv_video"			CV_VERSION_STR CV_EXT_STR) // �S�i�E�w�i�����A�g���b�L���O
#pragma comment(lib, CV_LIB		"opencv_objdetect"		CV_VERSION_STR CV_EXT_STR) // haar�ALBP�AHOG�Ȃǂ̃I�u�W�F�N�g���o��
#pragma comment(lib, CV_LIB		"opencv_features2d"	CV_VERSION_STR CV_EXT_STR) // SURF�AFAST�Ȃǂ̓������o
#pragma comment(lib, CV_LIB		"opencv_flann"			CV_VERSION_STR CV_EXT_STR) // �����ŋߖT����(FLANN)�Ȃ�
#pragma comment(lib, CV_LIB		"opencv_contrib"		CV_VERSION_STR CV_EXT_STR) // �����o�AMeanShift�Ȃ� �����S�ȏ�Ԃł͂Ȃ�
#pragma comment(lib, CV_LIB		"opencv_ml"			CV_VERSION_STR CV_EXT_STR) // SVM�A�u�[�X�e�B���O�Ȃǂ̋@�B�w�K
#pragma comment(lib, CV_LIB		"opencv_haartraining_engine"		CV_EXT_STR)


//>>>>SIFT�Ȃ�nonfree���C�u�������g���ꍇ�̓R�����g�A�E�g���O��<<<<
////�܂��Acv::initModule_nonfree();����������K�v������B
//#include <opencv2\nonfree\nonfree.hpp>
//#pragma comment(lib,CV_LIB	"opencv_nonfree" CV_VERSION_STR CV_EXT_STR)
