/**
 * @copyright  MIT License (c) 2020 Kushagra Agrawal and Kartik Venkat
 * @file  main.cpp
 * @brief main function with demo implementation
 * @author Kartik Venkat and Kushagra Agrawal
 */
#include <yolo.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <User.h>
#include <Utils.h>


/*
 * @brief This gets displayed if the help parameter is
 * passed as an argument.
 */
const char* keys =
    "{help h usage ? | | Usage examples: "
    "\n\t\t./object_detection_yolo.out --image=dog.jpg "
    "\n\t\t./object_detection_yolo.out --video=run_sm.mp4"
    "\n\t\t./object_detection_yolo.out --show_output}"
    "{image img        |<none>| input image   }"
    "{video vid       |<none>| input video   }"
    "{show_output       |<none>| show output   }";


/*
 * @brief main function
 * @param argc
 * @param argv
 * return type int
 */
int main(int argc, char** argv) {
  /*
   * @brief create objects of each class.
   */
  Yolo yolo;
  User user;
  Utils utils;

  cv::CommandLineParser parser(argc, argv, keys);
  parser.about("Use this script to run object "
               "detection using YOLO3 in OpenCV.");

  if (parser.has("help")) {
    parser.printMessage();
    return 0;
  }
  /*
   * @brief Run the DEMO algorithm.
   */
  yolo.humanDetection(parser, user, yolo, utils);
  return 0;
}



