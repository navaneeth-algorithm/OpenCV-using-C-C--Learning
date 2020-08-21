/*

Here the image file is written to new file
*/

#include <opencv2/opencv.hpp>
#include<iostream>



using namespace std;

int main(int arrgc, char** argv){

    cv::Mat image;
    image = cv::imread("assets/yogaposes.jpeg");

    if(image.empty()){
        return -1;
    }

    /*
    Process the image here i.e convert to grey scale , increase brightmess or blur or any other 
    processing
    */
    cv::Mat greyImage ;
    cv::cvtColor(image,greyImage,cv::COLOR_RGB2GRAY,1);

    
    bool isSuccess =  cv::imwrite("assets/yogagrey.jpeg",greyImage);

     if (isSuccess == false)
 {
  cout << "Failed to save the image" << endl;
  cin.get(); //wait for a key press
  return -1;
 }

    string winName = "yoga grey";

    cv::namedWindow(winName);
    cv::imshow(winName,greyImage);
    cv::waitKey(0);
    cv::destroyWindow(winName);
    return 0;
}