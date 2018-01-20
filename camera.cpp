#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
  VideoCapture cap("nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)1280, height=(int)720,format=(string)I420, framerate=(fraction)24/1 ! nvvidconv flip-method=0 ! video/x-raw, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink");

  if (!cap.isOpened())
    {
      cout << "Failed to open camera." << endl;
      return -1;
    }

  for(;;)
    {
      Mat frame;
      cap >> frame;
      imshow("original", frame);
      waitKey(1);
    }

  cap.release();
}
