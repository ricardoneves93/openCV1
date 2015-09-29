#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

class Exercise4
{
public:
	Exercise4(void);
	~Exercise4(void);
	void a();
	void b();
private:
	string saveDir;
};

