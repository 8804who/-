#include  "opencv2/opencv.hpp"

using namespace cv;

void main()
{
	Mat win = imread("D:/����/���� �ڷ�/4-1/USG��������/��ǻ�ͺ���/����/img/windows.jpg");
	Mat ryan = imread("D:/����/���� �ڷ�/4-1/USG��������/��ǻ�ͺ���/����/img/ryan.bmp");
	
	Mat roi = win(Rect(win.cols/4, win.rows/4, ryan.cols, ryan.rows));
	
	ryan.copyTo(roi);

	imshow("win", win);
	imshow("ryan", ryan);
	imshow("roi", roi);
	waitKey();
}