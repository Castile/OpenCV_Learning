#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
/*
	调整图像亮度与对比度
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
	char input[] = "输入";
	imshow(input, src);
	Mat dst = Mat::zeros(src.size(), src.type());
	//增加图像亮度和对比度
	int height = src.rows;
	int width = src.cols;
	double alpha = 1.5;
	double beta = 25;

	Mat ml;
	src.convertTo(ml, CV_32F);

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			//如果是三通道图像
			if (src.channels() == 3)
			{
				// 获取各个通道的像素值
				float b = ml.at<Vec3f>(row, col)[0];
				float g = ml.at<Vec3f>(row, col)[1];
				float r = ml.at<Vec3f>(row, col)[2];
				dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b * alpha + beta);
				dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g * alpha + beta);
				dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r * alpha + beta);
			}
			else if (src.channels() == 1) //单通道
			{
				float v = ml.at<uchar>(row, col);
				dst.at<uchar>(row, col) = saturate_cast<uchar>(v * alpha + beta);
			}
		}
	}
	char out[] = "输出窗口";
	namedWindow(out, WINDOW_AUTOSIZE);
	imshow(out, dst);
	waitKey(0);





}