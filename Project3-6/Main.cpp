#include  "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

const string imgPath = "D:/공부/수업 자료/4-1/USG공유대학/컴퓨터비전/과제/data/Practice3/butterfly.jpg";
const string imgPath2 = "D:/공부/수업 자료/4-1/USG공유대학/컴퓨터비전/과제/data/Practice3/butterfly2.jpg";

int main(int argc,  char** argv)
{
	Mat img = imread(imgPath), result;
	Mat img2 = imread(imgPath2), result2;
	vector<KeyPoint> kps;
	vector<KeyPoint> kps2;

	Ptr<Feature2D> sift = SIFT::create();

	sift->detect(img, kps);
	drawKeypoints(img, kps, result, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	imshow("result", result);

	Mat desc;
	sift->compute(img, kps, desc);
	cout << desc << endl;

	sift->detect(img2, kps2);
	drawKeypoints(img2, kps2, result2, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	imshow("result2", result2);

	waitKey();
	return 0;
}