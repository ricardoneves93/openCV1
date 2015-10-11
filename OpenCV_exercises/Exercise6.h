#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

class Exercise6
{
public:
	Exercise6(string imgDir);
	~Exercise6();
	void a();
	void b();
	void c();
	void d();
private:
	string imgDir;
};

