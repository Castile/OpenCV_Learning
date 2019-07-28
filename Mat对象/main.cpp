#include<opencv2/opencv.hpp>
#include<iostream>
#include<stdio.h>
using namespace std;
using namespace cv;

int main()
{
	Mat src;
	src = imread("../images/man.jpeg");
	if (src.empty())
	{
		cout << "ͼƬ����ʧ��" << endl;
		return -1;

	}
	namedWindow("input", WINDOW_AUTOSIZE);
	
	imshow("input", src);

#if 0
	Mat dst;
	dst = Mat(src.size(), src.type());
	dst = Scalar(127, 0, 255);
	namedWindow("output", WINDOW_AUTOSIZE);
	imshow("output", dst);
#endif
	//Mat dst = src.clone();//��������ͼƬ
	Mat dst;
	//src.copyTo(dst);//��������ͼƬ
	namedWindow("output", WINDOW_AUTOSIZE);
	cvtColor(src, dst, COLOR_BGR2GRAY); //ת����ɫ�ռ�
	cout << "src channels:" << src.channels() << endl;// 3
	cout << "dst channels:" << dst.channels() << endl; //1
	const uchar* firstrow = dst.ptr<uchar>(0);//��ȡ��һ�е�����ָ��
	//cout << "��һ�е�����ֵΪ��" << *firstrow << endl;
	printf("��һ�е�����ֵΪ��%d\n", *firstrow);

	int cols = dst.cols;
	int rows = dst.rows;
	cout << "dst's row = " << rows << endl; //438
	cout << "dst'cols = " << cols << endl; //480
	

	Mat M(100, 100, CV_8UC3, Scalar(0, 0, 255));
	//cout << M << endl;


	Mat out;
	//����һ ��С����
	Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(src, out, -1, kernel);

	Mat m2 = Mat::zeros(src.size(), src.type());

	imshow("output", m2);
	waitKey(0);

	return 0;
}