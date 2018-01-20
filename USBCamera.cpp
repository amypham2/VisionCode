#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
  VideoCapture cap(1);

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
