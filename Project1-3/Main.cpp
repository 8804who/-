#include  "opencv2/opencv.hpp"

using namespace cv;

void main()
{
	Mat win = imread("D:/공부/수업 자료/4-1/USG공유대학/컴퓨터비전/과제/img/windows.jpg");
	Mat ryan = imread("D:/공부/수업 자료/4-1/USG공유대학/컴퓨터비전/과제/img/ryan.bmp");
	
	Mat roi = win(Rect(win.cols/4, win.rows/4, ryan.cols, ryan.rows));
	
	ryan.copyTo(roi);

	imshow("win", win);
	imshow("ryan", ryan);
	imshow("roi", roi);
	waitKey();
}