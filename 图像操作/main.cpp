#include <opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	Mat src = imread("../images/girls.jpeg");
	if (!src.data)
	{
		cout << "ͼƬδ����..." << endl;
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);
#if 0
	Mat grayimg;
	cvtColor(src, grayimg, COLOR_BGR2GRAY);
	int height = grayimg.rows;
	int width = grayimg.cols;
	namedWindow("out", WINDOW_AUTOSIZE);
	//��ͨ��
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			int gray = grayimg.at<uchar>(row, col); //��ȡ����ֵ
			grayimg.at<uchar>(row, col) = 255 - gray; // ��ת����ֵ(��ƬЧ��)

		}
	}
	imshow("out", grayimg);
#endif


	Mat dst;
	dst.create(src.size(), src.type());
#if 0
	dst = src.clone();
	int height = src.rows;
	int width = src.cols;
	int nc = src.channels();
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (nc == 1) // ��ͨ��
			{
				int gray = dst.at<uchar>(row, col); //��ȡ����ֵ
				dst.at<uchar>(row, col) = 255 - gray; // ��ת����ֵ(��ƬЧ��)

			}
			else if (nc == 3) // ��ͨ��
			{
				// ����Ч��
				int b = dst.at<Vec3b>(row, col)[0];
				int g = dst.at<Vec3b>(row, col)[1];
				int r = dst.at<Vec3b>(row, col)[2];
				dst.at<Vec3b>(row, col)[0] = 255 - b;
				dst.at<Vec3b>(row, col)[1] = 255 - g;
				dst.at<Vec3b>(row, col)[2] = 255 - r;
			}
		}
	}

#endif
	bitwise_not(src, dst); //������Ĵ���Ч��һ��

	imshow("out", dst);
	waitKey(0);

	return 0;
}