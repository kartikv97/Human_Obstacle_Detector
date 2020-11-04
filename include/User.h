/**
 * @copyright  MIT License (c) 2020 Kushagra Agrawal and Kartik Venkat
 * @file  User.h
 * @brief User Class implementation
 * @author Kartik Venkat and Kushagra Agrawal
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

/**
 * @brief User class is responsible with methods that
 * take inputs from the user and also that save the final
 * output
 */
class User{
 private:
  /**
  * @brief private variable for image Path.
  */
  std::string imagePath = std::string("");
  /**
  * @brief private variable for video Path.
  */
  std::string videoPath = std::string("");
  /**
  * @brief private variable for output frame width.
  */
  int outputWidth{};
  /**
  * @brief private variable for output frame height.
  */
  int outputHeight{};

 public:
  /**
  * @brief  constructor for User class with no parameters.
  */
  User();
  /**
  * @brief sets the outputWidth value.
  * @param width
  * @return type void.
  */
  void setOutputWidth(int width);
  /**
  * @brief sets the outputHeight value.
  * @param height
  * @return type void.
  */
  void setOutputHeight(int height);
  /**
  * @brief returns the outputWidth value.
  * @param None
  * @return type int.
  */
  int getOutputWidth();
  /**
  * @brief returns the outputHeight value.
  * @param None
  * @return type int.
  */
  int getOutputHeight();
  /**
  * @brief sets the imagePath value.
  * @param path
  * @return type void.
  */
  void setImagePath(std::string path);
  /**
  * @brief returns the imagePath value.
  * @param None
  * @return type std::string.
  */
  std::string getImagePath();
  /**
  * @brief sets the videoPath value.
  * @param path
  * @return type void.
  */
  void setVideoPath(std::string path);
  /**
  * @brief returns the videoPath value.
  * @param None
  * @return type std::string.
  */
  std::string getVideoPath();
  /**
  * @brief returns the dataType value. ("image" or "video")
  * @param parser
  * @return type std::string.
  */
  std::string getDataType(cv::CommandLineParser parser);
  /**
  * @brief returns the path to the input image or video.
  * @param parser
  * @param dataType
  * @return type std::string.
  */
  std::string getDataPath(const cv::CommandLineParser& parser, const std::string& dataType);
  /**
  * @brief This function is responsible to handle all
  * image read/write operations
  * @param operation
  * @param frame
  * @return type cv::VideoCapture.
  */
  cv::VideoCapture processImage(const std::string& operation, cv::Mat frame);
  /**
  * @brief This function is responsible to handle all
  * video read/write operations
  * @param operation
  * @param frame
  * @param video
  * @return type cv::VideoCapture.
  */
  cv::VideoCapture processVideo(const std::string& operation, cv::Mat frame,cv::VideoWriter video);
};



