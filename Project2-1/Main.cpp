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
			cout << "data: " << data << endl;
			for (int i = 0; i < bbox.size(); i++) cout << bbox[i].x << ", " << bbox[i].y << endl;
			imshow("qrImage", qrImage);
		}
		imshow("frame", frame);
		waitKey(1);
	}
}