/**
 * @copyright  MIT License (c) 2020 Kushagra Agrawal and Kartik Venkat
 * @file  Utils.h
 * @brief Utils Class implementation
 * @author Kushagra Agrawal and Kartik Venkat
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <opencv2/opencv.hpp>
#include "Utils.h"

/**
 * @brief Constructor for the Utils class.
 */
Utils::Utils(){
    classesFile = "../coco.names";
    modelConfigurationFile = "../yolov3.cfg";
    modelWeightsFile = "../yolov3.weights";
}
/**
 * @brief It sets the Classes value.
 * @param ClassesValue
 * @return None
 */
void Utils::setClassesFile(const std::string classesValue) {
    classesFile = classesValue;
}
/**
 * @brief It gets the Classes file
 * @param None
 * @return Classes file
 */
std::string Utils::getClassesFile() {
    return classesFile;
}
/**
 * @brief It sets the model configuration value.
 * @param ModelConfigurationValue
 * @return None
 */
void Utils::setModelConfiguration(const std::string modelConfiguration) {
    modelConfigurationFile = modelConfiguration;
}
/**
 * @brief It gets model configuration file
 * @param None
 * @return Model configuration file
 */
std::string Utils::getModelConfiguration() {
    return modelConfigurationFile;
}
/**
 * @brief It sets the model weights value
 * @param ModelWeightsValue
 * @return None
 */
void Utils::setWeights(const std::string modelWeights) {
    modelWeightsFile = modelWeights;
}
/**
 * @brief It gets the model weights value.
 * @param None
 * @return ModelWeightsFile
 */
std::string Utils::getWeights() {
    return modelWeightsFile;
}
/**
 * @brief It adds classes in std::vector<std::string>.
 * @param None
 * @return void
 */
void Utils::setClasses() {
    std::ifstream ifs(classesFile.c_str());
    std::string line;
    while (std::getline(ifs, line))
        Classes.push_back(line);
}
/**
     * @brief It returns classes of type std::vector<std::string>.
     * @param None
     * @return std::vector<std::string>.
     */
std::vector<std::string> Utils::getClasses() {
    return Classes;
}
/**
 * @brief Destructor for Utils Class.
 */
Utils::~Utils() {

}