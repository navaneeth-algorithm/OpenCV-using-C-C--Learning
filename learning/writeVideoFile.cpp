/*

write video file to destination

*/


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv){

    cv::Mat imageFrame;
    int option;

    cout<<"1.From Camera 2. From File"<<endl;
    cin>>option;
cv::VideoCapture videoCapture;
    int frame_width;
    int frame_height;
    if(option==1){
        videoCapture =  cv::VideoCapture(0);
        
    } 
    else if(option==2){
        videoCapture = cv::VideoCapture("assets/cutedogs.mp4");

        
    }
    else{
        return -1;
    }

    if(videoCapture.isOpened()==false){
            return -1;
        }

    string windowNamed = "Video Writer";

    frame_width = videoCapture.get(cv::CAP_PROP_FRAME_WIDTH);
    frame_height = videoCapture.get(cv::CAP_PROP_FRAME_HEIGHT);


    cv::Size frameSize(frame_width,frame_height);

    cv::namedWindow(windowNamed);
 
    int fps = videoCapture.get(cv::CAP_PROP_FPS);
   int frames_per_Second = fps;
    cv::VideoWriter videoWriter("assets/greyVideo.avi",cv::VideoWriter::fourcc('M','J','P','G'),frames_per_Second,frameSize,true);

    if(videoWriter.isOpened()==false){
        return - 1;
    }

    while(true){

        bool isFinished = videoCapture.read(imageFrame);

        if(isFinished==false){
            break;
        }

        if(cv::waitKey(10)==27){
            
            //Wait for 10 sec & if ESC is pressed within 10 sec break from loop
            break;
        }

       // cv::Mat greyImage;
        //cv::cvtColor(imageFrame,greyImage,cv::COLOR_BGR2BGRA,4);
       // cv::cvtColor(imageFrame,greyImage,cv::COLOR_GRAY2BGR);
       // cv::resize(greyImage,greyImage,frameSize);

        videoWriter.write(imageFrame);
        cv::imshow(windowNamed,imageFrame);

    }

    videoWriter.release();

    return 0;
}