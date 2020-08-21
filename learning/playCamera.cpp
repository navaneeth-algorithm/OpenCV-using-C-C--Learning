/*

Load the Camera and display

*/

#include <opencv2/opencv.hpp>
#include <iostream>



using namespace std;

int main(int argc, char** argv){

cv::Mat imageFrame;
cv::VideoCapture cap(0);

if(cap.isOpened()==false){
    cout<<"Failed to open the camera"<<endl;
    return -1;
}
string windoName = "Mystery Camera";

//WINDOW NORMAL FRAME makes resizable window
cv::namedWindow(windoName,cv::WINDOW_NORMAL);
 double dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
 double dHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

 cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;

while(true){

    //For grey image set BL
    bool finished = cap.read(imageFrame);
    cv::Mat greyScale;
    cv::cvtColor(imageFrame,greyScale,cv::COLOR_RGB2GRAY,1);



    if(cv::waitKey(10)==27){
        cout<<"CLosed by pressing ESC"<<endl;
        break;
    }


    cv::imshow(windoName,greyScale);

    
}

cv::destroyWindow(windoName);
return 0;

}