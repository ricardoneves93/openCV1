#include "StdAfx.h"
#include "Exercise3.h"

Exercise3::Exercise3(string imageName) {this->imageName = "../img/" + imageName;}

void Exercise3::a()
{
	Mat image = imread(this->imageName);
	imshow("Color image", image);
	
	Mat imageGrey;
	cvtColor(image, imageGrey, COLOR_BGR2GRAY);
	imshow("Gray image", imageGrey);

	imwrite("../img/image_grey.jpg", imageGrey);
	waitKey(0);
}

void Exercise3::b() 
{
}

void Exercise3::c()
{
	Mat image = imread(this->imageName);
	if(!image.data)
	{
		cout << "No image data!" << endl;
		system("pause");
	}
	vector<Mat> channels(3);
	split(image, channels);
	
	vector<Mat> separatedChannels = this->showSeparatedChannels(channels);
	imshow("Blue channel", separatedChannels[0]);
	imshow("Green channel", separatedChannels[1]);
	imshow("Red channel", separatedChannels[2]);
	
	waitKey(0);


}

vector<Mat> Exercise3::showSeparatedChannels(vector<Mat> channels)
{
	vector<Mat> separatedChannels;
	// create each image for each channel
	for(int i = 0; i < 3; i++)
	{
		// Create material with all channels initialized to zero
		Mat zer = Mat::zeros(channels[0].rows, channels[0].cols, channels[0].type());
		vector<Mat> aux;
		// foreach channel inside image, creates three new materials
		for(int j = 0; j < 3; j++)
		{
			if(j == i)
				aux.push_back(channels[i]);
			else
				aux.push_back(zer);
		}

		Mat chann;
		merge(aux, chann);

		separatedChannels.push_back(chann);
	}

	return separatedChannels;
}

Exercise3::~Exercise3(void)
{
}
