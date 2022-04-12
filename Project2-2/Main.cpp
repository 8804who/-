#include  "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void main()
{
	Mat frame, qrImage;
	vector<Point> bbox;
	string data;
	VideoCapture cam(0);
	QRCodeDetector qr;

	while (true) {
		cam >> frame;
		data = qr.detectAndDecode(frame, bbox, qrImage);
		if (data.length() > 0)
		{
			putText(frame, data, bbox[0], FONT_ITALIC, 1, Scalar(255, 0, 0), 2);
			line(frame, bbox[0], bbox[1], Scalar(0, 255, 0), 2);
			line(frame, bbox[1], bbox[2], Scalar(255, 0, 0), 2);
			line(frame, bbox[2], bbox[3], Scalar(0, 0, 255), 2);
			line(frame, bbox[3], bbox[0], Scalar(255, 255, 255), 2);
			imshow("qrImage", qrImage);
		}
		imshow("frame", frame);
		waitKey(1);
	}
}