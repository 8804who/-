#include  "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

const string dataPath = "D:/공부/수업 자료/4-1/USG공유대학/컴퓨터비전/과제/data/Practice3/3-2/";
const string queryFileName = "query.jpg";

Mat calcHist(Mat& input) {
	Mat output(1, 256, CV_32F, Scalar(0));

	for (int i = 0; i < input.rows; i++)
		for (int j = 0; j < input.cols; j++)
			output.at<float>(input.at<uchar>(i, j))++;
	output /= input.total();
	return output;
}

double calcDistance(Mat& input1, Mat& input2)
{
	double distance = 0.0;

	for (int i = 0; i < input1.cols; i++)
		distance += (input1.at<float>(i) - input2.at<float>(i)) * (input1.at<float>(i) - input2.at<float>(i));

	return distance;
}

void main()
{
	Mat queryImg = imread(dataPath + queryFileName, IMREAD_GRAYSCALE);
	Mat queryVector = calcHist(queryImg);

	for (int i = 1; i <= 50; i++) {
		char temp[3];
		sprintf_s(temp, "%d", i);
		cout << temp << endl;
		Mat targetImg = imread(dataPath + temp+".jpg", IMREAD_GRAYSCALE);
		Mat targetVector = calcHist(targetImg);
		cout << calcDistance(targetVector, queryVector) << endl;
	}
}