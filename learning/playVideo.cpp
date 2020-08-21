/*

Load the Video file and play it using openCV

*/

#include <opencv2/opencv.hpp>
#include <iostream>



using namespace std;

int main(int argc, char** argv){

cv::Mat imageFrame;
cv::VideoCapture cap("assets/cutedogs.mp4");

if(cap.isOpened()==false){
    cout<<"Failed to open the video"<<endl;
    return -1;
}
string windoName = "SHIBUA";

//WINDOW NORMAL FRAME makes resizable window
cv::namedWindow(windoName,cv::WINDOW_NORMAL);
cout<<"TOTAL FRAME "<<cap.get(cv::CAP_PROP_FRAME_COUNT)<<endl;

while(true){

    //For grey image set BL
    bool finished = cap.read(imageFrame);



    if(cv::waitKey(10)==27){
        cout<<"CLosed by pressing ESC"<<endl;
        break;
    }

    if(finished==false){
        cout<<"COMPLETED video"<<endl;
        break;
    }

    cv::imshow(windoName,imageFrame);

    
}

cv::destroyWindow(windoName);
return 0;

}