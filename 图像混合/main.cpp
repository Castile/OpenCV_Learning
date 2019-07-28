#include<opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/************************************************************************/
/* ͼ����                ����
*
2019��7��28��20:48:35/
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
	// ��ʾͼ��
	imshow("girls", src1);
	imshow("fish", src2);


	double alpha = 0.2;
	//ֻ�д�С�����Ͷ���ͬ���ܽ��л��
	if (src1.rows==src2.rows && src1.cols==src2.cols && src1.type() == src2.type())
	{
		addWeighted(src1, alpha, src2, 1.0 - alpha, 0, dst);
		namedWindow("out", WINDOW_AUTOSIZE);
		imshow("out", dst);

		waitKey(0);
	}
	else
	{
		cout << "����ͼƬ�Ĵ�С��һ�°���" << endl;
		return -1;
	}

	return 0;
}