#include <opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
int main()
{
	Mat src, dst;
	src = imread("../images/elephant.jpeg");
	if (!src.data)
	{
		cout << "加载图片出错！" << endl;
		return -1;
	}
	namedWindow("input image",WINDOW_AUTOSIZE);
	imshow("input image", src);

#if 0

	/************************************************************************/
	/*1. 自己手动实现                                                                     */
	/************************************************************************/
	 //先获取图片的行数和列数
	int rows = src.rows;
	int offset = src.channels(); // 三个通道， 一列有三个通道数
	int cols = (src.cols -1) * offset;
	// 初始化目标像素矩阵输出
	dst = Mat::zeros(src.size(), src.type()); // 全黑，大小和类型和源输入大小和类型一致
	for (int row = 1; row < rows - 1; row++)//行，从第2行开始，因为第一行没有上一行，无法计算。最后一行也没有下一行，无法计算
	{
		const uchar* previous = src.ptr<uchar>(row - 1); // 获取前一行的像素指针
		const uchar* current = src.ptr<uchar>(row); // 当前行的像素指针
		const uchar* next = src.ptr<uchar>(row + 1); // 下一行的像素指针
		uchar* output = dst.ptr<uchar>(row); // 对当前行的每一列进行计算
		for (int col = offset; col < cols; col++)
		{
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offset] + current[col + offset] + previous[col] + next[col]));
		}

	}

#endif

	/************************************************************************/
	/* 使用OpenCV的API                                                                     */
	/************************************************************************/
	double t = getTickCount();
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0); // 掩模 ，卷积核
	filter2D(src, dst, src.depth(), kernel);  // src.depth()原图的深度， 也可用-1表示
	double timeconsume = (getTickCount() - t) / getTickFrequency();
	cout << "时间消耗：" << timeconsume << endl;  // 0.02 运行时间很快

	namedWindow("contrast image", WINDOW_AUTOSIZE);
	imshow("contrast image", dst);
	waitKey(0);
	return 0;

}




