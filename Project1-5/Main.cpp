#include  "opencv2/opencv.hpp"

using namespace cv;

void main()
{
	Mat win = imread("D:/공부/수업 자료/4-1/USG공유대학/컴퓨터비전/과제/img/windows.jpg");
	Mat ryan = imread("D:/공부/수업 자료/4-1/USG공유대학/컴퓨터비전/과제/img/ryan.png", IMREAD_UNCHANGED);
	
	std::vector<Mat> channels;
	split(ryan, channels);

	Mat mask = channels[3];
	channels.pop_back();

	Mat color_ryan;
	merge(channels, color_ryan);

	Mat roi = win(Rect(win.cols/4, win.rows/4, ryan.cols, ryan.rows));
	

	color_ryan.copyTo(roi, mask);

	imshow("win", win);
	waitKey();
}