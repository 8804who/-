#include  "opencv2/opencv.hpp"

using namespace cv;

void main()
{
	Mat img = imread("D:/����/���� �ڷ�/4-1/USG��������/��ǻ�ͺ���/����/img/windows.jpg");
	Mat gray, small, smallgray;

	cvtColor(img, gray, COLOR_BGR2GRAY);

	resize(img, small, img.size() / 2);
	cvtColor(small, smallgray, COLOR_BGR2GRAY);

	imshow("img", img);
	imshow("gray", gray);
	imshow("small", small);
	imshow("smallgray", smallgray);
	waitKey();
}