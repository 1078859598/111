#include <iostream>
#include <opencv.hpp>

using namespace cv;
using namespace std;

float Lut[256] = { 0 };


void LutBuild(float gammar)
{
	//建立Lut图
	for (int i = 0; i < 256; i++)
	{
		Lut[i] = pow((i*1.0 / 255), gammar) * 255;
	}
}
void Gammar(Mat srcMat)
{
	//srcMat.copyTo(dstMat);
	int height = srcMat.rows; //行数
	int width = srcMat.cols;//每行元素数量
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			srcMat.at<uchar>(j, i) = Lut[srcMat.at<uchar>(j, i)];
		}
	}





}
int main()
{

	cv::Mat srcMat = imread("C:/Users/HS/Desktop/1.jpg", 0);

	LutBuild(0.45);
	Gammar(srcMat);
	imshow("srcMat", srcMat);

	waitKey(0);


	return 0;
}