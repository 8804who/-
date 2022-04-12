#include  "opencv2/opencv.hpp"

using namespace cv;

void main()
{
	Mat win = imread("D:/����/���� �ڷ�/4-1/USG��������/��ǻ�ͺ���/����/img/windows.jpg");
	Mat ryan = imread("D:/����/���� �ڷ�/4-1/USG��������/��ǻ�ͺ���/����/img/ryan.png", IMREAD_UNCHANGED);
	
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