#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
/*
	����ͼ��������Աȶ�
	2019-7-28 21:31:18
*/
int main()
{
	Mat src = imread("../images/blackdog.jpeg");
	if (!src.data)
	{
		cout << "image can not load..." << endl;
		return -1;
	}




}