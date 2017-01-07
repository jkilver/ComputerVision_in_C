//#include <opencv\cv.h>   // This is the original code, but I couldn't get VideoCapture work correctly.
#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main() {
	Mat image1;          //Create Matrix to store image
	
	char* filename = ".\\input\\ps1-1-a-1.png";
	image1 = imread(filename, CV_LOAD_IMAGE_COLOR);
	Mat channel[3];
	split(image1, channel);

	Mat blue = channel[0];
	Mat green = channel[1];
	Mat red = channel[2];

	Mat swapped[3];
	swapped[0] = red;
	swapped[1] = green;
	swapped[2] = blue;

	Mat output;
	merge(swapped, 3, output);
	
	filename = ".\\output\\ps1-2-a-1.png";
	imwrite(filename, output);
	


	//namedWindow("Display window", WINDOW_AUTOSIZE);
	//imshow("Display window", output);

	waitKey(0);
	return 0;
}