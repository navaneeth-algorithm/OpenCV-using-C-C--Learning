## To Install OpenCV in ubuntu follow this procedure

#### Step 1. Update the Ubuntu System Package
```sh
 sudo apt-get update && sudo apt-get upgrade
```
#### Step 2. Install Required tools and packages
```sh
sudo apt-get install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
```
```sh
 sudo apt-get install python3.5-dev python3-numpy libtbb2 libtbb-dev
```

##### If you encounter error like below screenshot, then follow the step 2.a
![Screenshot](https://i2.wp.com/techawarey.com/wp-content/uploads/2020/04/OpenCV_python_3_5_error.png?resize=660%2C203)

```sh
sudo apt-get install libjpeg-dev libpng-dev libtiff5-dev libjasper-dev libdc1394-22-dev libeigen3-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev sphinx-common libtbb-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libavutil-dev libavfilter-dev libavresample-dev
```

##### if you encounter error like below screenshot, then follow the step 2.b
![Screenshot](https://i1.wp.com/techawarey.com/wp-content/uploads/2020/04/OpenCV_libjasper_Error.png?resize=660%2C214)

##### Step 2.a Add repository and ppa
```sh
sudo apt-add-repository ppa:deadsnakes/ppa
```

##### Step 2.b Add repository and ppa
```sh
sudo apt-add-repository "deb http://security.ubuntu.com/ubuntu xenial-security main"
```
```sh
sudo apt update
```
```sh
sudo apt install libjasper1 libjasper-dev
```

#### Step 3. Download OpenCV Sources using git
```sh
sudo -s
```
```sh
cd /opt
```
```sh
git clone https://github.com/Itseez/opencv.git
```
```sh
git clone https://github.com/Itseez/opencv_contrib.git
```

#### Step 4. Build & Install OpenCV
```sh
cd opencv
```
```sh
mkdir release
```
```sh
cd release
```
```sh
cmake -D BUILD_TIFF=ON -D WITH_CUDA=OFF -D ENABLE_AVX=OFF -D WITH_OPENGL=OFF -D WITH_OPENCL=OFF -D WITH_IPP=OFF -D WITH_TBB=ON -D BUILD_TBB=ON -D WITH_EIGEN=OFF -D WITH_V4L=OFF -D WITH_VTK=OFF -D BUILD_TESTS=OFF -D BUILD_PERF_TESTS=OFF -D OPENCV_GENERATE_PKGCONFIG=ON -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv_contrib/modules /opt/opencv/
```

```sh
make -j4
```
```sh
make install
```
```sh
ldconfig
```
```sh
exit

```
```sh
cd ~
```
#### Step 5. Check OpenCV version installed
```sh
pkg-config --modversion opencv
```
##### If you encounter error like “pakage opencv not found” then follow step 5.a.

##### Step 5.a. Find & Set “opencv.pc” file path
```sh
apt-file search opencv.pc
```
```sh
ls /usr/local/lib/pkgconfig/
```
```sh
sudo cp /usr/local/lib/pkgconfig/opencv4.pc  /usr/lib/x86_64-linux-gnu/pkgconfig/opencv.pc
```
```sh
pkg-config --modversion opencv 
```

![Screenshot](https://i1.wp.com/techawarey.com/wp-content/uploads/2020/04/OpenCV_final.png?resize=660%2C200)

#### Step 6. Compile & Run a Test Program 
```sh
mkdir opencv_test
```
```sh
cd opencv_test
```
```sh
gedit test.cpp 
```
#### Copy & Paste the code psoted in Step 6

```sh
g++ test.cpp -o testoutput -std=c++11 `pkg-config --cflags --libs opencv`
```
```sh
$ ./testoutput
```





#### To Compile C++ opencv program use command
```sh
g++ test.cpp -o testoutput -std=c++11 `pkg-config --cflags --libs opencv`
```
#### To run the program
```sh
./testoutput
```

### Output
![output](https://i2.wp.com/techawarey.com/wp-content/uploads/2020/04/OpenCV_TestCodeOutput.png?resize=768%2C523)

## Link and credit 
http://techawarey.com/programming/install-opencv-c-c-in-ubuntu-18-04-lts-step-by-step-guide/

