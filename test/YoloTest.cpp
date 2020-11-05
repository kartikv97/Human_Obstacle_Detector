/**
 * @copyright  MIT License (c) 2020 Kushagra Agrawal and Kartik Venkat
 * @file  YoloTest.cpp
 * @brief Test source file for testing the Yolo
 *        class methods.Includes all the required headers
 * @author Kushagra Agrawal and Kartik Venkat
 */

#include <gtest/gtest.h>
#include <yolo.h>
#include <Utils.h>
#include <User.h>

Yolo yolo;
Utils utils;
User User;

double val = 2;


const char* keys1 =
    "{help h usage ? | | Usage examples: "
    "\n\t\t./object_detection_yolo.out --image=dog.jpg "
    "\n\t\t./object_detection_yolo.out --video=run_sm.mp4"
    "\n\t\t./object_detection_yolo.out --show_output}"
    "{image img        | ../dog.jpg | input image   }"
    "{video vid       |<none>| input video   }"
    "{show_output       |<none>| show output   }";
const char* keys4 =
    "{image img        |<none>| input image   }"
    "{video vid       |../dog.jpg| input video   }"
    "{show_output       |<none>| show output   }";

/**
 * @brief Test case for setConfigurtionThreshold method of YOLOv3 class. The
 * test checks whether value set for confidence is same as the value input
 * by the getConfigurationThreshold method.
 */
TEST(checkGetterSetter, checkConfThreshold) {
    yolo.setConfigurationThreshold(val);
    EXPECT_EQ(yolo.getConfigurationThreshold(), val);
}

/**
 * @brief Test case for setNmsThreshold method of YOLOv3 class. The
 * test checks whether value set for nmsThreshold is same as the value input
 * by the getNmsThreshold method.
 */
TEST(checkGetterSetter, checknmsThreshold) {
    yolo.setNmsThreshold(val);
    EXPECT_EQ(yolo.getNmsThreshold(), val);
}

/**
 * @brief Test case for setInputWidth method of YOLOv3 class. The
 * test checks whether value set for InputWidth is same as the value input
 * by the getInputWidth method.
 */
TEST(checkGetterSetter, checkInputWidth) {
    yolo.setInputWidth(val);
    EXPECT_EQ(yolo.getInputWidth(), val);
}

/**
 * @brief Test case for setInputHeight method of YOLOv3 class. The
 * test checks whether value set for InputHeight is same as the value input
 * by the getInputHeight method.
 */
TEST(checkGetterSetter, checkInputHeight) {
    yolo.setInputHeight(val);
    EXPECT_EQ(yolo.getInputHeight(), val);
}
/**
 * @brief Test case for drawBox method of Yolo class.
 */
TEST(checkYolo, checkDrawBox) {
    utils.setClassesFile("../coco.names");
    std::vector<std::string> classes = utils.getClasses();
    cv::Mat frame = cv::imread("../dog.jpg", 0);
    int rows = frame.rows;
    int cols = frame.cols;
    yolo.drawBox(0, 99.0, 0, 0, 5, 5, frame, classes);
    EXPECT_EQ(frame.rows, rows);
    EXPECT_EQ(frame.cols, cols);
}
/**
 * @brief Test case for humanDetection method of Yolo class.
 */
TEST(checkYolo, humanDetection) {
  cv::Mat blob;
  utils.setClasses();
  std::vector<std::string> classes = utils.getClasses();
  // Load the network
  cv::dnn::Net net = cv::dnn::readNetFromDarknet(utils.getModelConfiguration(),
                                                 utils.getWeights());
  cv::Mat frame = cv::imread("../dog.jpg");
  cv::dnn::blobFromImage(frame,  blob, 1/255.0,
                         cv::Size(416,
                                  416),
                         cv::Scalar(0, 0, 0),
                         true, false);
  net.setInput(blob);
  std::vector<cv::Mat> outs;
  net.forward(outs, yolo.getOutputNames(net));
  EXPECT_NO_FATAL_FAILURE(yolo.removeBox(frame, outs, 0.5, classes));
}
/**
 * @brief Test case for humanDetection method of Yolo class.
 */
TEST(checkYolo, humanDetectionAlgo) {
  int argc = 0;
  const char *argv = "";
  cv::CommandLineParser parser(argc, &argv, keys1);
  yolo.setConfigurationThreshold(0.5);
  yolo.setInputHeight(416);
  yolo.setInputWidth(416);
  yolo.setNmsThreshold(0.4);
  EXPECT_NO_FATAL_FAILURE(yolo.humanDetection(parser, User, yolo, utils));
}
/**
 * @brief Test case for humanDetection method of Yolo class.
 */
TEST(checkYolo, humanDetectionAlgo2) {
  int argc = 0;
  const char *argv = "";
  cv::CommandLineParser parser(argc, &argv, keys4);
  yolo.setConfigurationThreshold(0.5);
  yolo.setInputHeight(416);
  yolo.setInputWidth(416);
  yolo.setNmsThreshold(0.4);
  EXPECT_NO_FATAL_FAILURE(yolo.humanDetection(parser, User, yolo, utils));
}
