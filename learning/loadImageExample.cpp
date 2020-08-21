/*
//Creates and loads the image from the disk
Displays it using opencv window

*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
int main(int argc, char** argv){

    cv::Mat image = cv::imread("assets/yogaposes.jpeg");
    if(image.empty()){
        cout<<"Could not open file"<<endl;
        cin.get();
        return -1;
    }
    string windowName="YOGA";
    cv::namedWindow(windowName);
    cv::imshow(windowName,image);
   
    cv::waitKey(0);
     cv::destroyWindow(windowName);

    
    return 0;
    
}
