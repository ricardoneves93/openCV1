#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

class Exercise2
{
public:
	Exercise2(string imageName);
	~Exercise2();
	void a();
	void b();
private:
	string imageName;
};

