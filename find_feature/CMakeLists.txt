
cmake_minimum_required(VERSION 2.8)
project( find_feature )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( find_feature find_feature.cpp )
target_link_libraries( find_feature ${OpenCV_LIBS} )
