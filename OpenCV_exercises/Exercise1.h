#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

class Exercise1
{
public:
	Exercise1(string ImageName);
	void a();
	void b();
	~Exercise1(void);
private:
	string imageName;
};

