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
		cout << "����ͼƬ����" << endl;
		return -1;
	}
	namedWindow("input image",WINDOW_AUTOSIZE);
	imshow("input image", src);

#if 0

	/************************************************************************/
	/*1. �Լ��ֶ�ʵ��                                                                     */
	/************************************************************************/
	 //�Ȼ�ȡͼƬ������������
	int rows = src.rows;
	int offset = src.channels(); // ����ͨ���� һ��������ͨ����
	int cols = (src.cols -1) * offset;
	// ��ʼ��Ŀ�����ؾ������
	dst = Mat::zeros(src.size(), src.type()); // ȫ�ڣ���С�����ͺ�Դ�����С������һ��
	for (int row = 1; row < rows - 1; row++)//�У��ӵ�2�п�ʼ����Ϊ��һ��û����һ�У��޷����㡣���һ��Ҳû����һ�У��޷�����
	{
		const uchar* previous = src.ptr<uchar>(row - 1); // ��ȡǰһ�е�����ָ��
		const uchar* current = src.ptr<uchar>(row); // ��ǰ�е�����ָ��
		const uchar* next = src.ptr<uchar>(row + 1); // ��һ�е�����ָ��
		uchar* output = dst.ptr<uchar>(row); // �Ե�ǰ�е�ÿһ�н��м���
		for (int col = offset; col < cols; col++)
		{
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offset] + current[col + offset] + previous[col] + next[col]));
		}

	}

#endif

	/************************************************************************/
	/* ʹ��OpenCV��API                                                                     */
	/************************************************************************/
	double t = getTickCount();
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0); // ��ģ �������
	filter2D(src, dst, src.depth(), kernel);  // src.depth()ԭͼ����ȣ� Ҳ����-1��ʾ
	double timeconsume = (getTickCount() - t) / getTickFrequency();
	cout << "ʱ�����ģ�" << timeconsume << endl;  // 0.02 ����ʱ��ܿ�

	namedWindow("contrast image", WINDOW_AUTOSIZE);
	imshow("contrast image", dst);
	waitKey(0);
	return 0;

}




