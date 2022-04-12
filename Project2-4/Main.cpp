#include  "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void main()
{
	Mat cFrame, vFrame, qrImage, wFrame;
	vector<Point2f> bbox;
	string data;
	VideoCapture cam(0), video;
	QRCodeDetector qr;
	double width, height;
	vector<Point2f> v_bbox;

	while (true) {
		cam >> cFrame;
		data = qr.detectAndDecode(cFrame, bbox, qrImage);
		if (data.length() > 0)
		{
			if (!video.isOpened()) {
				video.open("../data/" + data);
				width = video.get(CAP_PROP_FRAME_WIDTH);
				height = video.get(CAP_PROP_FRAME_HEIGHT);
				v_bbox.push_back(Point2f(0,0));
				v_bbox.push_back(Point2f(width, 0));
				v_bbox.push_back(Point2f(width, height));
				v_bbox.push_back(Point2f(0, height));
			}
			Mat H = findHomography(v_bbox, bbox);
			video >> vFrame;
			warpPerspective(vFrame, wFrame, H, cFrame.size());
			imshow("video", wFrame);
			imshow("qrImage", qrImage);
		}
		imshow("frame", cFrame);
		waitKey(1);
	}
}