#include<opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/************************************************************************/
/* 图像混合                操作
*
2019年7月28日20:48:35/
/************************************************************************/
int main()
{
	Mat src1, src2, dst;
	src1 = imread("../images/girls.jpeg");
	if (src1.empty())
	{
		cout << "can not load girls" << endl;
		return -1;
	}
	src2 = imread("../images/fish.jpeg");
	if (src2.empty())
	{
		cout << "can not load fish" << endl;
		return -1;
	}
	// 显示图像
	imshow("girls", src1);
	imshow("fish", src2);


	double alpha = 0.2;
	//只有大小和类型都相同才能进行混合
	if (src1.rows==src2.rows && src1.cols==src2.cols && src1.type() == src2.type())
	{
		addWeighted(src1, alpha, src2, 1.0 - alpha, 0, dst);
		namedWindow("out", WINDOW_AUTOSIZE);
		imshow("out", dst);

		waitKey(0);
	}
	else
	{
		cout << "两张图片的大小不一致啊！" << endl;
		return -1;
	}

	return 0;
}