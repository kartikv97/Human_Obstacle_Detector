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

Yolo yolo;
Utils utils;
double val = 2;

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

