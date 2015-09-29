#include "stdafx.h"
#include "Exercise2.h"


Exercise2::Exercise2(string imageName){ this->imageName = "../img/" + imageName; }

void Exercise2::a()
{
	Mat img1, img2, img3;
	img1 = imread(imageName);
	img2 = img1;
	img1.copyTo(img3);
	flip(img3, img2, 1);
	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	waitKey(0);
}

void Exercise2::b()
{
	Mat mat;

	mat = Mat(50, 200, CV_8UC1, Scalar(100));
	mat.at<uchar>(mat.rows / 2, mat.cols / 2) = 255;
	imshow("point on center", mat);
	waitKey(0);
}



Exercise2::~Exercise2()
{
}
