/**
 * @copyright  MIT License (c) 2020 Kushagra Agrawal and Kartik Venkat
 * @file  UtilsTest.cpp
 * @brief Test source file for testing the Utils
 *        class methods.Includes all the required headers
 * @author Kushagra Agrawal and Kartik Venkat
 */

#include <gtest/gtest.h>
#include "Utils.h"

Utils util;

/**
 * @brief It checks whether the SetClassesFile sets the class file correctly or not.
 */
TEST(checkUtilsGetterSetter, ClassesFile) {
    util.setClassesFile("../coco.names");
    EXPECT_EQ(util.getClassesFile(), "../coco.names");
}

/**
 * @brief It checks whether the SetModelConfiguration sets the model configuration file correctly or not.
 */
TEST(checkUtilsGetterSetter, ModelConfigurationFile) {
    util.setModelConfiguration("../yolov3.cfg");
    EXPECT_EQ(util.getModelConfiguration(), "../yolov3.cfg");
}

/**
 * @brief It checks whether the SetWeights sets the weights file correctly or not.
 */
TEST(checkUtilsGetterSetter, ModelWeightsFile) {
    util.setWeights("../yolov3.weights");
    EXPECT_EQ(util.getWeights(), "../yolov3.weights");
}
/**
 * @brief Test case for getClasses method of Utils class.
 */
TEST(checkUtilsGetterSetter, checkClassesSize) {
    util.setClassesFile("../coco.names");
    util.setClasses();
    std::vector<std::string> classes = util.getClasses();
    EXPECT_EQ(classes.size(), 80);
}

/**
 * @brief Test case for setClasses method of Utils class.
 */
TEST(checkAddClasses, checkForCorrectInput) {
    EXPECT_NO_FATAL_FAILURE({
                                util.setClasses();
                            });
}

