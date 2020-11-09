/**
 * @copyright  MIT License (c) 2020 Kushagra Agrawal and Kartik Venkat
 * @file  main.cpp
 * @brief main function with unit tests
 * @author Kartik Venkat and Kushagra Agrawal
 */
#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
