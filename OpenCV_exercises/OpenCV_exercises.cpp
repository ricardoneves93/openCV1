// OpenCV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Exercise1.h"
#include "Exercise3.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{

	// Exercise 1
    Exercise1 *exercise1 = new Exercise1("open.jpg");
	//exercise1->a();
	//exercise1->b();
	delete exercise1;

	// Exercise 3
	Exercise3 *exercise3 = new Exercise3("open.png");
	//exercise3->a();
	exercise3->c();
}