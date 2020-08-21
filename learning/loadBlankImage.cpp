/*
Load Blank Image

*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
int main(int argc, char** argv){

    cv::Mat blankImage(600,800,CV_8UC3, cv::Scalar(100,250,30));
    string windowName = "Blank Image";

    cv::namedWindow(windowName);

    cv::imshow(windowName,blankImage);

    cv::waitKey(0);
    cv::destroyWindow(windowName);
}