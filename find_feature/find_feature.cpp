
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdio>

#include <opencv2/core/core.hpp>
//#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;


int main(int argc, char* argv[])
{
Size patternsize(3,5); //interior number of corners
Mat gray = imread( "/home/messnix/Downloads/calib.io_checker_210x297_6x4_40-1.png", CV_BGR2GRAY ); //source image 
vector<Point2f> corners; //this will be filled by the detected corners




//CALIB_CB_FAST_CHECK saves a lot of time on images
//that do not contain any chessboard corners
bool patternfound = findChessboardCorners(gray, patternsize, corners, CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE + CALIB_CB_FAST_CHECK);


cout<<"the bool is:"<<patternfound<<endl;



drawChessboardCorners(gray, patternsize, Mat(corners), patternfound);

    while(1){
        imshow("window",gray);
        cvWaitKey(33);
    }

return 0;


}
