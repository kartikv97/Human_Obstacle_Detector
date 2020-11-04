/**
 * @copyright  MIT License (c) 2020 Kushagra Agrawal and Kartik Venkat
 * @file  Yolo.cpp
 * @brief Yolo Class implementation
 * @author Kartik Venkat and Kushagra Agrawal
 */
#include <yolo.h>
#include <iostream>
#include <User.h>
#include <Utils.h>
#include <vector>

#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>



/**
 * @brief  constructor for Yolo class.
 */
Yolo::Yolo() {
  inputHeight = 416;
  inputWidth = 416;
  configurationThreshold = 0.5;
  nmsThreshold = 0.4;
}

/**
 * @brief sets the inputWidth value.
 * @param width
 * @return type void.
 */
void Yolo::setInputWidth(int width) {
  inputWidth = width;
}

/**
 * @brief sets the inputHeight value.
 * @param height
 * @return type void.
 */
void Yolo::setInputHeight(int height) {
  inputHeight = height;
}

/**
 * @brief sets the configurationThreshold value.
 * @param configThres
 * @return type void.
 */
void Yolo::setConfigurationThreshold(float configThres) {
  configurationThreshold = configThres;
}

/**
 * @brief sets the nmsThreshold value.
 * @param nmsThres
 * @return type void.
 */
void Yolo::setNmsThreshold(float nmsThres) {
  nmsThreshold = nmsThres;
}

/**
 * @brief returns the inputWidth value.
 * @param None
 * @return type int.
 */
int Yolo::getInputWidth() {
  return inputWidth;
}

/**
 * @brief returns the inputHeight value.
 * @param None
 * @return type int.
 */
int Yolo::getInputHeight() {
  return inputHeight;
}

/**
 * @brief returns the configurationThreshold value.
 * @param None
 * @return type float.
 */
float Yolo::getConfigurationThreshold() {
  return configurationThreshold;
}

/**
 * @brief returns the nmsThreshold value.
 * @param None
 * @return type float.
 */
float Yolo::getNmsThreshold() {
  return nmsThreshold;
}
/**
 * @brief This function performs postprocessing
 * on the image/video frames and draws the best
 * bounding box for each detection.
 * @param frame
 * @param outs
 * @param confThreshold
 * @param classes
 * @return None.
 */
void Yolo::removeBox(cv::Mat& frame, const std::vector<cv::Mat>& outs
    , float confThreshold, const std::vector<std::string>& classes) {
  std::vector<int> classIds;
  std::vector<float> confidences;
  std::vector<cv::Rect> boxes;

  for (const auto & out : outs) {
    /* @brief Scan through all the bounding boxes output from the network and keep only the
     * ones with high confidence scores. Assign the box's class label as the class
     * with the highest score for the box.
     */
    auto* data = (float*)out.data;
    for (int j = 0; j < out.rows; ++j, data += out.cols) {
      cv::Mat scores = out.row(j).colRange(5, out.cols);
      cv::Point classIdPoint;
      double confidence;

      // Get the value and location of the maximum score
      minMaxLoc(scores, nullptr, &confidence, nullptr, &classIdPoint);
      if (confidence > confThreshold) {
        int centerX = static_cast<int>(data[0] * frame.cols);
        int centerY = static_cast<int>(data[1] * frame.rows);
        int width = static_cast<int>(data[2] * frame.cols);
        int height = static_cast<int>(data[3] * frame.rows);
        int left = centerX - width / 2;
        int top = centerY - height / 2;

        classIds.push_back(classIdPoint.x);
        confidences.push_back(static_cast<float>(confidence));
        boxes.emplace_back(left, top, width, height);
      }
    }
  }

  /* @brief Perform non maximum suppression to eliminate redundant overlapping boxes with
   * lower confidences
   */
  std::vector<int> indices;
  cv::dnn::NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);
  for (int idx : indices) {
    cv::Rect box = boxes[idx];
    /* @brief Draw bounding box for each detected object.
     */
    drawBox(classIds[idx], confidences[idx], box.x, box.y,
            box.x + box.width, box.y + box.height, frame, classes);
  }
}

/* @brief This function returns the label
 * names of the detected objects
 * @param net
 * @return type std::vector<std::string>
 */
std::vector<std::string> Yolo::getOutputNames(const cv::dnn::Net& net) {
  static std::vector<cv::String> names;
  if (names.empty()) {
    // Get the indices of the output layers, i.e. the layers
    // with unconnected outputs
    std::vector<int> outLayers = net.getUnconnectedOutLayers();

    // get the names of all the layers in the network
    std::vector<cv::String> layersNames = net.getLayerNames();

    // Get the names of the output layers in names
    names.resize(outLayers.size());
    for (size_t i = 0; i < outLayers.size(); ++i)
      names[i] = layersNames[outLayers[i] - 1];
  }
  return names;
}

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
void Yolo::drawBox(int classId, float conf, int left, int top,
                   int right, int bottom, cv::Mat &frame,
                   std::vector<std::string> classes) {
  // Draw a rectangle displaying the bounding box
  rectangle(frame, cv::Point(left, top),
            cv::Point(right, bottom),
            cv::Scalar(255, 178, 50), 3);
  // Get the label for the class name and its confidence
  std::string label = cv::format("%.2f", conf);
  if (!classes.empty()) {
    CV_Assert(classId < static_cast<int>(classes.size()));
    label = classes[classId] + ":" + label;
  }
  // Display the label at the top of the bounding box
  int baseLine;
  cv::Size labelSize = getTextSize(label, cv::FONT_HERSHEY_SIMPLEX,
                                   0.5, 1, &baseLine);
  top = std::max(top, labelSize.height);
  rectangle(frame, cv::Point(left, top - round(1.5*labelSize.height)),
            cv::Point(left + round(1.5*labelSize.width), top + baseLine),
            cv::Scalar(255, 255, 255), cv::FILLED);
  putText(frame, label, cv::Point(left, top), cv::FONT_HERSHEY_SIMPLEX,
          0.75, cv::Scalar(0, 0, 0), 1);
}

/*
 * @brief This function forms the backbone of the human detection algorithm.
 * This function calls other member classes, performs object detection and
 * saves the output.
 * @param parser
 * @param user
 * @param yolo
 * @param utils
 */
void Yolo::humanDetection(cv::CommandLineParser parser,
                          User user, Yolo yolo,
                          Utils utils) {
  std::vector<std::string> classes;

  // Load names of classes
  classes = utils.getClasses();

  // Load the network
  cv::dnn::Net net = cv::dnn::readNetFromDarknet(utils.getModelConfiguration(),
                                                 utils.getWeights());
  net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
  net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);

  // Open a video file or an image file or a camera stream.
  std::string str, outputFile;
  cv::VideoCapture cap;
  cv::VideoWriter video;
  cv::Mat frame, blob;

  /* @brief Load the input image/video based on command line arguments
   */
  try {
    std::string dataType = user.getDataType(parser);
    std::string dataPath = user.getDataPath(parser, dataType);
    if (dataType == "image") {
      user.setImagePath(dataPath);
      cap = user.processImage("read", frame);
    }
    if (dataType == "video") {
      user.setVideoPath(dataPath);
      cap = user.processVideo("read", frame, video);
      user.setOutputWidth(cap.get(cv::CAP_PROP_FRAME_WIDTH));
      user.setOutputHeight(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    }
  }
  catch (...) {
    std::cout << "Could not open the input image/video stream" << std::endl;
  }
  /* @brief Create an instance of video writer with initial parameters.
   */
  if (parser.has("video")) {
    video.open("../output/videoOutputs/OutputVideo.avi",
               cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),
               24, cv::Size(user.getOutputWidth(),
                            user.getOutputHeight()), true);
  }
  /* Process each frame.
   */
  while (cv::waitKey(1) < 0) {
    /* @brief Get frame from the video/image
     */
    cap >> frame;

    /* @brief Stop the program if reached end of video
     */
    if (frame.empty()) {
      std::cout << "Done processing !!!" << std::endl;
      std::cout << "Output file is stored in the output folder "
      << outputFile << std::endl;
      cap.release();
      video.release();
      cv::waitKey(3000);
      break;
    }

    /* @brief Create a 4D blob from a frame.
    */
    cv::dnn::blobFromImage(frame, blob, 1/255.0,
                           cv::Size(getInputWidth(),
                                    getInputHeight()),
                                    cv::Scalar(0, 0, 0),
                                    true, false);

    /* @brief Sets the input to the network
     */
    net.setInput(blob);

    /* @brief Runs the forward pass to get output of the output layers
     */
    std::vector<cv::Mat> outs;
    net.forward(outs, yolo.getOutputNames(net));

    /* @brief Remove the bounding boxes with low confidence
     */
    yolo.removeBox(frame, outs, getConfigurationThreshold(), classes);

    /* @brief Put efficiency information. The function getPerfProfile
     * returns the overall time for inference(t) and the timings for
     * each of the layers(in layersTimes)
     */
    std::vector<double> layersTimes;
    double freq = cv::getTickFrequency() / 1000;
    double t = net.getPerfProfile(layersTimes) / freq;
    std::string label = cv::format("Inference time for a frame : %.2f ms", t);
    putText(frame, label, cv::Point(0, 15), cv::FONT_HERSHEY_SIMPLEX,
            0.5, cv::Scalar(0, 0, 255));

    /* Write the frame with the detection boxes
     */
    cv::Mat detectedFrame;
    frame.convertTo(detectedFrame, CV_8U);

    if (parser.has("image"))
      user.processImage("write", frame);

    if (parser.has("video")) {
      user.setOutputWidth(frame.size().width);
      user.setOutputHeight(frame.size().height);
      user.processVideo("write", frame, video);
    }
    if (parser.has("show_output")) {
      /* @brief Create a window to display the output
       */
      static const std::string kWinName = " Human/object detection in OpenCV";
      namedWindow(kWinName, cv::WINDOW_NORMAL);
      imshow(kWinName, frame);
    }
  }

  cap.release();
  video.release();
  if (!parser.has("image")) video.release();
}
