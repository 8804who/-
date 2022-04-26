#include  "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

const string imgPath = "D:/공부/수업 자료/4-1/USG공유대학/컴퓨터비전/과제/data/Practice3/butterfly.jpg";

Mat gray;
int std_dev = 10;

void GaussianBlur(int, void*) 
{
	if (std_dev) {
		Mat result;
		GaussianBlur(gray, result, Size(0, 0), (double)std_dev / 10.0);
		imshow("result", result);
	}
}

int main(int argc,  char** argv)
{
	gray = imread(imgPath, IMREAD_GRAYSCALE);
	imshow("gray", gray);
	createTrackbar("10*std_dev: ", "gray", &std_dev, 100, GaussianBlur);
	GaussianBlur(0, 0);
	waitKey();
	return 0;
}