//#include<iostream>
//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
//using namespace cv;
//int main() {
//	Mat img = imread("F:\\vs\\testOpencv\\testOpencv\\1.jpg");
//	namedWindow("picture");
//	imshow("picture", img);
//	waitKey(8000);
//	return 0;
//}

#include <opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	Mat src = imread("F:\\vs\\testOpencv\\testOpencv\\1.jpg");
	if (src.empty())
	{
		cout << "¿Õ..." << endl;
		return -1;
	}

	namedWindow("Test OpenCv setup", WINDOW_AUTOSIZE);
	imshow("Test OpenCv setup", src);

	namedWindow("output window", WINDOW_AUTOSIZE);
	Mat output_img;
	cvtColor(src, output_img,COLOR_BGR2HSV);

	imshow("output window", output_img);

	// ±£´æÍ¼Æ¬
	imwrite("../images/hslout.png", output_img);

	waitKey(0);

	return 0;
}