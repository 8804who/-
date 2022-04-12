#include  "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

const string dataPath = "D:/공부/수업 자료/4-1/USG공유대학/컴퓨터비전/과제/data/Practice3/3-1/";
const string queryFileName = "query.bmp";
const vector<string> targetFileNames = { "1.bmp", "2.bmp", "3.bmp", "4.bmp", "5.bmp", "6.bmp"};

Mat calcHist(Mat& input) {
	Mat output(1, 256, CV_32F, Scalar(0));

	for (int i = 0; i < input.rows; i++)
		for (int j = 0; j < input.cols; j++)
			output.at<float>(input.at<uchar>(i, j))++;
	output /= input.total();
	return output;
}

void main()
{
	Mat queryImg = imread(dataPath + queryFileName, IMREAD_GRAYSCALE);

}