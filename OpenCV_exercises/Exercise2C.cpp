#include "stdafx.h"
#include "Exercise2C.h"


Exercise2C::Exercise2C(string imageName)
{
	this->image = imread("../img/" + imageName);
}

Exercise2C::Exercise2C(int x, int y, int intensity)
{
	this->image = Mat(x, y, CV_8UC1, Scalar(intensity));
}


Mat Exercise2C::getImage()
{
	return this->image;
}


Exercise2C::~Exercise2C()
{
}
