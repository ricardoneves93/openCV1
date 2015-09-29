#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

class Exercise2C
{
public:
	Exercise2C(string imageName);
	Exercise2C(int x, int y, int intensity);
	~Exercise2C();
	Mat getImage();
private:
	Mat image;

};

