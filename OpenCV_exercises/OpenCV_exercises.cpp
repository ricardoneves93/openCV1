// OpenCV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Exercise1.h"
#include "Exercise2.h"
#include "Exercise2C.h"
#include "Exercise3.h"
#include "Exercise4.h"
#include "Exercise5.h"
#include "Exercise6.h"
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

	// Exercise 2
	Exercise2 *exercise2 = new Exercise2("open.png");
	//exercise2->a();
	//exercise2->b();
	delete exercise2;

	// Exercise 2C
	/*
	Exercise2C *exercise2c = new Exercise2C("open.png");
	imshow("Image from file", exercise2c->getImage());
	Exercise2C *exercise2c1 = new Exercise2C(500, 500, 0);
	imshow("Image created", exercise2c1->getImage());
	waitKey(0);
	delete exercise2c;
	delete exercise2c1;
	*/

	// Exercise 3
	Exercise3 *exercise3 = new Exercise3("open.png");
	//exercise3->a();
	//exercise3->c();
	//exercise3->d();
	delete exercise3;

	//Exercise 4
	Exercise4 *exercise4 = new Exercise4();
	//exercise4->a();
	//exercise4->b();
	delete exercise4;

	//Exercise 5
	Exercise5 *exercise5 = new Exercise5();
	//exercise5->a();
	//exercise5->b();
	delete exercise5;

	//Exercise 6
	Exercise6 *exercise6 = new Exercise6("open.png");
	exercise6->a();
	//exercise6->b();
	//exercise6->c();
	//exercise6->d();
	delete exercise6;
}