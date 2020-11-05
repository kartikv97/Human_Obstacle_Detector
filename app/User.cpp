/**
 * @copyright  MIT License (c) 2020 Kushagra Agrawal and Kartik Venkat
 * @file  User.cpp
 * @brief User Class implementation
 * @author Kartik Venkat and Kushagra Agrawal
 */
#include <User.h>
#include <Utils.h>
#include <yolo.h>
#include <utility>



#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn/dnn.hpp>


/**
 * @brief  constructor for User class.
 */
User::User()= default;

/**
* @brief sets the outputWidth value.
* @param width
* @return type void.
*/
void User::setOutputWidth(int width) {
  outputWidth = width;
}
/**
* @brief sets the outputHeight value.
* @param height
* @return type void.
*/
void User::setOutputHeight(int height) {
  outputHeight = height;
}
/**
* @brief returns the outputWidth value.
* @param None
* @return type int.
*/
int User::getOutputWidth() {
  return outputWidth;
}
/**
* @brief returns the outputHeight value.
* @param None
* @return type int.
*/
int User::getOutputHeight() {
  return outputHeight;
}

/**
* @brief sets the imagePath value.
* @param path
* @return type void.
*/
void User::setImagePath(std::string path) {
  imagePath = std::move(path);
}
/**
* @brief returns the imagePath value.
* @param None
* @return type std::string.
*/
std::string User::getImagePath() {
  return imagePath;
}
/**
* @brief sets the videoPath value.
* @param path
* @return type void.
*/
void User::setVideoPath(std::string path) {
  videoPath = std::move(path);
}
/**
* @brief returns the videoPath value.
* @param None
* @return type std::string.
*/
std::string User::getVideoPath() {
  return videoPath;
}
/**
* @brief returns the dataType value. ("image" or "video")
* @param parser
* @return type std::string.
*/
std::string User::getDataType(cv::CommandLineParser parser) {
  if (parser.has("image") || parser.has("img")) {
    std::string inputType = "image";
    return inputType;
  } else if (parser.has("video")|| parser.has("vid")) {
    std::string inputType = "video";
    return inputType;
  } else {
    std::string Error = "Error";
    std::cout<< "invalid key specified\n";
    return Error;
  }
}
/**
 * @brief returns the path to the input image or video.
 * @param parser
 * @param dataType
 * @return type std::string.
 */
std::string User::getDataPath(const cv::CommandLineParser& parser,
                              const std::string& dataType) {
  if (parser.has("image") || parser.has("img")) {
    imagePath = parser.get<std::string>("image");
    return imagePath;
  } else if (parser.has("video") || parser.has("vid")) {
    videoPath = parser.get<std::string>("video");
    return videoPath;
  } else {
    std::string Error = "Error";
    std::cout<< "path to " << dataType <<
    " does not exist. Please enter a valid path.\n";
    return Error;
  }
}
/**
* @brief This function is responsible to handle all
* image read/write operations
* @param operationcd
* @param frame
* @return type cv::VideoCapture.
*/

cv::VideoCapture User::processImage(const std::string& operation,
                                    cv::Mat frame ) {
  if (operation == "read") {
    cv::VideoCapture capture;
    capture.open(imagePath);
    return capture;
  } else if (operation == "write") {
    std::string outputPath = "../output/imageOutputs/OutputImage.jpg";
    cv::imwrite(outputPath, frame);
    std::cout<< "images saved at "<< outputPath<< "\n";
    return cv::VideoCapture();
  }
}
/**
* @brief This function is responsible to handle all
* video read/write operations
* @param operation
* @param frame
* @param video
* @return type cv::VideoCapture.
*/
cv::VideoCapture User::processVideo(const std::string& operation,
                                    cv::Mat frame , cv::VideoWriter video) {
  if (operation == "read") {
    cv::VideoCapture capture;
    capture.open(videoPath);
    return capture;
  } else if (operation == "write") {
    cv::Mat newFrame;
    cv::resize(frame, newFrame, cv::Size(getOutputWidth(), getOutputHeight()));
    video.write(newFrame);
    return cv::VideoCapture();
  }
}




