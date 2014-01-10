#pragma once
// ヘッダーファイル
#include <opencv2/opencv.hpp>

// バージョン取得
#define CV_VERSION_STR CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)

//#ifdef _WIN64
////#define CV_LIB "C:\\OpenCV\\OpenCV" CV_VERSION_STR "\\x64\\vc11\\lib\\"
//#define CV_LIB "C:\\OpenSourceLibrary\\OpenCV" CVAUX_STR(CV_MAJOR_VERSION) "." CVAUX_STR(CV_MINOR_VERSION) "."CVAUX_STR(CV_SUBMINOR_VERSION) "\\x64\\vc11\\lib\\"
//#else
////#define CV_LIB "C:\\OpenCV\\OpenCV" CV_VERSION_STR "\\x86\\vc11\\lib\\"
//#define CV_LIB "C:\\OpenSourceLibrary\\OpenCV" CVAUX_STR(CV_MAJOR_VERSION) "." CVAUX_STR(CV_MINOR_VERSION) "."CVAUX_STR(CV_SUBMINOR_VERSION) "\\x86\\vc11\\lib\\"
//#endif
#define CV_LIB ""


// ビルドモード
#ifdef _DEBUG
#define CV_EXT_STR "d.lib"
#else
#define CV_EXT_STR ".lib"
#endif

// ライブラリのリンク（不要な物はコメントアウト）
#pragma comment(lib, CV_LIB		"opencv_core"            CV_VERSION_STR CV_EXT_STR) // メモリ確保・解放、行列演算、描画など
#pragma comment(lib, CV_LIB		"opencv_highgui"        CV_VERSION_STR CV_EXT_STR) // ウィンドウなどGUI、ファイル読み込み・保存、ビデオファイル、カメラなど
#pragma comment(lib, CV_LIB		"opencv_imgproc"		CV_VERSION_STR CV_EXT_STR) // 画像処理、一般的なフィルタ処理など
#pragma comment(lib, CV_LIB		"opencv_calib3d"		CV_VERSION_STR CV_EXT_STR) // カメラキャリブレーション、ステレオカメラなど
#pragma comment(lib, CV_LIB		"opencv_gpu"			CV_VERSION_STR CV_EXT_STR) // GPU(CUDA)による行列演算、画像処理など ※ver2.2時点ではβ版
#pragma comment(lib, CV_LIB		"opencv_video"			CV_VERSION_STR CV_EXT_STR) // 全景・背景分離、トラッキング
#pragma comment(lib, CV_LIB		"opencv_objdetect"		CV_VERSION_STR CV_EXT_STR) // haar、LBP、HOGなどのオブジェクト検出器
#pragma comment(lib, CV_LIB		"opencv_features2d"	CV_VERSION_STR CV_EXT_STR) // SURF、FASTなどの特徴抽出
#pragma comment(lib, CV_LIB		"opencv_flann"			CV_VERSION_STR CV_EXT_STR) // 高速最近傍処理(FLANN)など
#pragma comment(lib, CV_LIB		"opencv_contrib"		CV_VERSION_STR CV_EXT_STR) // 肌検出、MeanShiftなど ※完全な状態ではない
#pragma comment(lib, CV_LIB		"opencv_ml"			CV_VERSION_STR CV_EXT_STR) // SVM、ブースティングなどの機械学習
#pragma comment(lib, CV_LIB		"opencv_haartraining_engine"		CV_EXT_STR)


//>>>>SIFTなどnonfreeライブラリを使う場合はコメントアウトを外す<<<<
////また、cv::initModule_nonfree();を実効する必要がある。
//#include <opencv2\nonfree\nonfree.hpp>
//#pragma comment(lib,CV_LIB	"opencv_nonfree" CV_VERSION_STR CV_EXT_STR)
