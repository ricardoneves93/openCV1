#include "StdAfx.h"
#include "Exercise4.h"


Exercise4::Exercise4(void)
{
	this->saveDir = "../img/video_frame.jpg";
}

void Exercise4::a(void)
{
	VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
	{
		cout << "Could not open default camera!" << endl;
		system("pause");
	}
	Mat grayScale;
    namedWindow("webcam_color", 1);
    for(;;)
    {
        Mat frame;
        cap >> frame;
        imshow("webcam_color", frame);
        if(waitKey(30) >= 0) imwrite(this->saveDir, frame);
		if(waitKey(27) >= 0) break;

    }
       
}

void Exercise4::b(void)
{
	VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
	{
		cout << "Could not open default camera!" << endl;
		system("pause");
	}
	Mat grayScale;
    namedWindow("webcam_color", 1);
	namedWindow("webcam_grey_scale", 1);
    for(;;)
    {
        Mat frame;
        cap >> frame;
        imshow("webcam_color", frame);
		cvtColor(frame, grayScale, CV_BGR2GRAY);
		imshow("webcam_grey_scale", grayScale);
		if(waitKey(27) >= 0) break;

    }
}


Exercise4::~Exercise4(void)
{
}
