/**
 * @copyright  MIT License (c) 2020 Kushagra Agrawal and Kartik Venkat
 * @file  UserTest.cpp
 * @brief Test source file for testing the User
 *        class methods.Includes all the required headers
 * @author Kushagra Agrawal and Kartik Venkat
 */

#include <gtest/gtest.h>
#include "User.h"

double vals = 2;
User user;

const char* keys =
    "{help h usage ? | | Usage examples: \n\t\t./object_detection_yolo.out "
    "--image=dog.jpg \n\t\t./object_detection_yolo.out --video=run_sm.mp4}"
    "\n\t\t./object_detection_yolo.out --show_output}"
    "{image img        |<none>| input image   }"
    "{video vid       |<none>| input video   }"
    "{show_output       |<none>| show output   }";
/**
 * @ brief Test case for getOutputWidth method of User class.
 */
TEST(checkGetterSetter, outputWidth) {
    user.setOutputWidth(vals);
    EXPECT_EQ(user.getOutputWidth(), vals);
}
/**
 * @ brief Test case for getOutputHeight method of User class.
 */
TEST(checkGetterSetter, outputHeight) {
    user.setOutputHeight(vals);
    EXPECT_EQ(user.getOutputHeight(), vals);
}
/**
 * @ brief Test case for getImagePath method of User class.
 */
TEST(checkGetterSetter, checkImagePath) {
    user.setImagePath("image");
    EXPECT_EQ(user.getImagePath(), "image");
}
/**
 * @ brief Test case for getVideoPath method of User class.
 */
TEST(checkGetterSetter, checkVideoPath) {
    user.setVideoPath("video");
    EXPECT_EQ(user.getVideoPath(), "video");
}

