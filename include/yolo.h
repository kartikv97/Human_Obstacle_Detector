/**
 * @copyright  MIT License (c) 2020 Kushagra Agrawal and Kartik Venkat
 * @file  yolo.h
 * @brief Yolo Class implementation
 * @author Kartik Venkat and Kushagra Agrawal
 */
#pragma once

#include <iostream>
#include <vector>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "User.h"
#include "Utils.h"

/**
 * @brief YOLOv3 class responsible for running object detection on image or video.
 */
class Yolo {
 private:
  /**
  * @brief private variable for inputWidth.
  */
  int inputWidth{0};
  /**
  * @brief private variable for inputHeight.
  */
  int inputHeight{0};
  /**
  * @brief private variable for configurationThreshold.
  */
  float configurationThreshold{0};
  /**
  * @brief private variable for nmsThreshold.
  */
  float nmsThreshold{0};

 public:
  /**
  * @brief  constructor for Yolo class with no parameters.
  */
  Yolo();
  /**
  * @brief sets the inputWidth value.
  * @param width
  * @return type void.
  */
  void setInputWidth(int width);
  /**
  * @brief sets the inputHeight value.
  * @param height
  * @return type void.
  */
  void setInputHeight(int height);
  /**
  * @brief sets the configurationThreshold value.
  * @param configThres
  * @return type void.
  */
  void setConfigurationThreshold(float configThres);
  /**
  * @brief sets the nmsThreshold value.
  * @param nmsThres
  * @return type void.
  */
  void setNmsThreshold(float nmsThres);
  /**
  * @brief returns the inputWidth value.
  * @param None
  * @return type int.
  */
  int getInputWidth();
  /**
  * @brief returns the inputHeight value.
  * @param None
  * @return type int.
  */
  int getInputHeight();
  /**
  * @brief returns the configurationThreshold value.
  * @param None
  * @return type float.
  */
  float getConfigurationThreshold();
  /*
  * @brief returns the nmsThreshold value.
  * @param None
  * @return type float.
  */
  float getNmsThreshold();
  /*
   * @brief This function performs postprocessing
   * on the image/video frames and draws the best
   * bounding box for each detection.
   * @param frame
   * @param outs
   * @param confThreshold
   * @param classes
   * @return None.
   */
  void removeBox(cv::Mat& frame, const std::vector<cv::Mat>& outs ,float confThreshold, std::vector<std::string> classes);
  /*
   * @brief This function draws the bounding box around the object and adds text labels to the image.
   * @param classId
   * @param conf
   * @param left
   * @param right
   * @param bottom
   * @param &frame
   * @param classes
   * @return None
   */
  static void drawBox(int classId, float conf, int left, int top, int right, int bottom, cv::Mat &frame, std::vector<std::string> classes );
  /* @brief This function returns the label
   * names of the detected objects
   * @param net
   * @return type std::vector<std::string>
   */
  static std::vector<std::string> getOutputNames(const cv::dnn::Net& net);
  /*
   * @brief This function forms the backbone of the human detection algorithm.
   * This function calls other member classes, performs object detection and
   * saves the output.
   * @param parser
   * @param user
   * @param yolo
   * @param utils
   */
  void humanDetection(cv::CommandLineParser parser, User user, Yolo yolo, Utils utils);

};

