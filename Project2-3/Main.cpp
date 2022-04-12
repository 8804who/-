#include  "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void main()
{
	Mat cFrame, vFrame, qrImage;
	vector<Point> bbox;
	string data;
	VideoCapture cam(0), video;
	QRCodeDetector qr;

	while (true) {
		cam >> cFrame;
		data = qr.detectAndDecode(cFrame, bbox, qrImage);
		if (data.length() > 0)
		{
			if(!video.isOpened())
				video.open("../data/"+data);
			video >> vFrame;
			imshow("video", vFrame);

			putText(cFrame, data, bbox[0], FONT_ITALIC, 1, Scalar(255, 0, 0), 2);
			line(cFrame, bbox[0], bbox[1], Scalar(0, 255, 0), 2);
			line(cFrame, bbox[1], bbox[2], Scalar(255, 0, 0), 2);
			line(cFrame, bbox[2], bbox[3], Scalar(0, 0, 255), 2);
			line(cFrame, bbox[3], bbox[0], Scalar(255, 255, 255), 2);
			imshow("qrImage", qrImage);
		}
		imshow("frame", cFrame);
		waitKey(1);
	}
}