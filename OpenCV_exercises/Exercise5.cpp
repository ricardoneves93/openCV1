#include "StdAfx.h"
#include "Exercise5.h"


Exercise5::Exercise5(void){this->imgDir = "../img/low_contrast.jpg";}

// Draw the histogram window
Mat imHist(Mat hist, float scaleX=1, float scaleY=1){
  double maxVal=0;
  // finds the min value and the max value
  minMaxLoc(hist, 0, &maxVal, 0, 0);
  int rows = 64; //default height size
  int cols = hist.rows; //get the width size from the histogram
  Mat histImg = Mat::zeros(rows*scaleX, cols*scaleY, CV_8UC3);
  //for each bin
  for(int i=0;i<cols-1;i++) {
    float histValue = hist.at<float>(i,0);
    float nextValue = hist.at<float>(i+1,0);
    Point pt1 = Point(i*scaleX, rows*scaleY);
    Point pt2 = Point(i*scaleX+scaleX, rows*scaleY);
    Point pt3 = Point(i*scaleX+scaleX, (rows-nextValue*rows/maxVal)*scaleY);
    Point pt4 = Point(i*scaleX, (rows-nextValue*rows/maxVal)*scaleY);
 
    int numPts = 5;
    Point pts[] = {pt1, pt2, pt3, pt4, pt1};
 
    fillConvexPoly(histImg, pts, numPts, Scalar(255,255,255));
  }
  return histImg;
}

void Exercise5::a()
{
	// read image
	Mat img_after, img_lab;
	Mat img = imread(this->imgDir);

	imshow("Image Before", img);
	
	//Hold the histogram
	MatND hist;
	Mat histImg;
	int nbins = 256; // lets hold 256 levels
	int hsize[] = { nbins }; // just one dimension
	float range[] = { 0, 255 };
	const float *ranges[] = { range };
	int chnls[] = {0};


	// create colors channels
	vector<Mat> colors(3);
	split(img, colors);
	

	// compute for all colors
    calcHist(&colors[0], 1, chnls, Mat(), hist, 1, hsize, ranges);
    histImg = imHist(hist,3,3);
    imshow("Blue Not eq",histImg);

	calcHist(&colors[1], 1, chnls, Mat(), hist, 1, hsize, ranges);
    histImg = imHist(hist,3,3);
    imshow("Green Not eq",histImg);

    calcHist(&colors[2], 1, chnls, Mat(), hist, 1, hsize, ranges);
    histImg = imHist(hist,3,3);
    imshow("Red Not eq",histImg);


	// convert to YCrCb

    cvtColor(img ,img_lab ,CV_BGR2Lab);

    vector<Mat> channels;
    split(img_lab, channels);

	cout << channels[0].rows << endl;

    equalizeHist(channels[0], channels[0]);

    Mat result;
    merge(channels, img_lab);

    cvtColor(img_lab , result, CV_Lab2BGR);


	// show equalized histograms
	vector<Mat> rgb_channels;
    split(result, rgb_channels);

    calcHist(&rgb_channels[0], 1, chnls, Mat(), hist, 1, hsize, ranges);
    histImg = imHist(hist,3,3);
    imshow("Blue eq",histImg);

	calcHist(&rgb_channels[1], 1, chnls, Mat(), hist, 1, hsize, ranges);
    histImg = imHist(hist,3,3);
    imshow("Green eq",histImg);

    calcHist(&rgb_channels[2], 1, chnls, Mat(), hist, 1, hsize, ranges);
    histImg = imHist(hist,3,3);
    imshow("Red eq",histImg);

	imshow("Image After", result);

	waitKey(0);

}


void Exercise5::b()
{

	//Hold the histogram
	MatND hist;
	Mat histImg;
	int nbins = 256; // lets hold 256 levels
	int hsize[] = { nbins }; // just one dimension
	float range[] = { 0, 255 };
	const float *ranges[] = { range };
	int chnls[] = {0};


	// READ RGB color image and convert it to Lab
    Mat bgr_image = imread(this->imgDir);
    Mat lab_image;

    cvtColor(bgr_image, lab_image, CV_BGR2Lab);

    // Extract the L channel
    vector<Mat> lab_planes(3);
    split(lab_image, lab_planes);  // now we have the L image in lab_planes[0]


    // apply the CLAHE algorithm to the L channel
    Ptr<cv::CLAHE> clahe = createCLAHE();
    clahe->setClipLimit(4);
    Mat dst;
    clahe->apply(lab_planes[0], dst);

    // Merge the the color planes back into an Lab image
    dst.copyTo(lab_planes[0]);
    merge(lab_planes, lab_image);

   // convert back to RGB
   Mat image_clahe;
   cvtColor(lab_image, image_clahe, CV_Lab2BGR);

   // display the results  (you might also want to see lab_planes[0] before and after).
   imshow("image original", bgr_image);
   imshow("image CLAHE", image_clahe);

							
   
   
								/*SHOW HISTOGRAMS*/

   // Show original histogram
   vector<Mat> src_channels;
   split(bgr_image, src_channels);

   calcHist(&src_channels[0], 1, chnls, Mat(), hist, 1, hsize, ranges);
   histImg = imHist(hist,3,3);
   imshow("Blue",histImg);

   calcHist(&src_channels[1], 1, chnls, Mat(), hist, 1, hsize, ranges);
   histImg = imHist(hist,3,3);
   imshow("Green",histImg);

   calcHist(&src_channels[2], 1, chnls, Mat(), hist, 1, hsize, ranges);
   histImg = imHist(hist,3,3);
   imshow("Red",histImg);

   // Show equalized histogram
   vector<Mat> rgb_channels;
   split(image_clahe, rgb_channels);

   calcHist(&rgb_channels[0], 1, chnls, Mat(), hist, 1, hsize, ranges);
   histImg = imHist(hist,3,3);
   imshow("Blue eq",histImg);

   calcHist(&rgb_channels[1], 1, chnls, Mat(), hist, 1, hsize, ranges);
   histImg = imHist(hist,3,3);
   imshow("Green eq",histImg);

   calcHist(&rgb_channels[2], 1, chnls, Mat(), hist, 1, hsize, ranges);
   histImg = imHist(hist,3,3);
   imshow("Red eq",histImg);

   waitKey();

}


Exercise5::~Exercise5(void)
{
}
