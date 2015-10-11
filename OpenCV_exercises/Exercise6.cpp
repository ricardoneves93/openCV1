#include "stdafx.h"
#include "Exercise6.h"


Exercise6::Exercise6(string imgDir)
{
	this->imgDir = "../img/" + imgDir;
}


//Mean filter
void  Exercise6::a()
{
	Mat img = imread(this->imgDir);
	Mat dst;
	imshow("Original Image", img);
	int MAX_KERNEL_LENGTH = 31;

	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		blur(img, dst, Size(i, i));
	}

	imshow("Blured Image", dst);

	waitKey(0);

}

//Gaussian filter
void  Exercise6::b()
{
	Mat img = imread(this->imgDir);
	Mat dst;
	imshow("Original Image", img);
	int MAX_KERNEL_LENGTH = 31;

	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		GaussianBlur(img, dst, Size(i, i), 0, 0);
	}

	imshow("Blured Image", dst);

	waitKey(0);
}

//Median filter
void  Exercise6::c()
{
	Mat img = imread(this->imgDir);
	Mat dst;
	imshow("Original Image", img);
	int MAX_KERNEL_LENGTH = 31;

	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		medianBlur(img, dst, i);
	}

	imshow("Blured Image", dst);

	waitKey(0);

}

//bilateral filter
void  Exercise6::d()
{
	Mat img = imread(this->imgDir);
	Mat dst;
	imshow("Original Image", img);
	int MAX_KERNEL_LENGTH = 31;

	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		bilateralFilter(img, dst, i, i*2, i/2);
	}

	imshow("Blured Image", dst);

	waitKey(0);

}


Exercise6::~Exercise6()
{
}
