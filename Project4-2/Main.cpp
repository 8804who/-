#include  "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

const string bookPath = "D:/공부/수업 자료/4-1/USG공유대학/컴퓨터비전/과제/data/Practice4/book.jpg";
const string camPath = "D:/공부/수업 자료/4-1/USG공유대학/컴퓨터비전/과제/data/Practice4/cam.jpg";

int main(int argc,  char** argv)
{
	Mat book = imread(bookPath);
	Mat cam = imread(camPath);
	
	vector <KeyPoint> bookKPs, camKPs;
	Mat bookDesc, camDesc;

	Ptr<Feature2D> sift = SIFT::create();

	sift->detectAndCompute(book, Mat(), bookKPs, bookDesc);
	sift->detectAndCompute(cam, Mat(), camKPs, camDesc);

	BFMatcher matcher(NORM_L2SQR);
	vector<DMatch> matches;

	matcher.match(bookDesc, camDesc, matches);

	vector<Point2f> bookPoints, camPoints;
	
	for (int i = 0; i < matches.size(); i++) {
		bookPoints.push_back(bookKPs[matches[i].queryIdx].pt);
		camPoints.push_back(camKPs[matches[i].trainIdx].pt);
	}

	Mat inlier;
	Mat H = findHomography(bookPoints, camPoints, RANSAC, 5.0,  inlier);
	int nInlier = countNonZero(inlier);

	if(nInlier>=100){
		Mat warpedBook;
		warpPerspective(book, warpedBook, H, cam.size());
		imshow("warpedBook", warpedBook);
	}

	waitKey();
	return 0;
}