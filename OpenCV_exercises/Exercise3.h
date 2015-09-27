#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

class Exercise3
{
public:
	Exercise3(string imageName);
	~Exercise3(void);
	void a();
	void b();
	void c();
	void d();
private:
	string imageName;
	vector<Mat> showSeparatedChannels(vector<Mat> channels);
};

