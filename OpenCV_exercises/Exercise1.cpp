#include "StdAfx.h"
#include "Exercise1.h"

Exercise1::Exercise1(string imageName) {this->imageName = "../img/" + imageName;}

void Exercise1::a()
{
	Mat image;
	image = imread(this->imageName);
	if(!image.data)
	{
		cout << "No image data!" << endl;
	}	
	else 
	{
		imshow(this->imageName, image);
		cout << "Height: " << image.rows << endl;
		cout << "Width: " << image.cols << endl;
		waitKey(0);
	}
}

void Exercise1::b()
{
	Mat image;
	image = imread(this->imageName);
	if(!image.data)
	{
		cout << "No image data!" << endl;
		system("pause");
	}	
	else 
	{
		istringstream iss(this->imageName);
		vector<string> tokens;
		string token;
		while(getline(iss, token, '.'))
		{
			if(!token.empty())
				tokens.push_back(token);
		}
		
		imwrite("../" + tokens[0] + ".bmp", image);
		cout << "Image written with success!" << endl;
		system("pause");
	}
}


Exercise1::~Exercise1(void)
{
}
