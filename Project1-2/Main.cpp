#include  "opencv2/opencv.hpp"

using namespace cv;

void main()
{
	Mat img = imread("D:/공부/수업 자료/4-1/USG공유대학/컴퓨터비전/과제/img/windows.jpg");
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