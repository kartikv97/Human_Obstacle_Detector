/**
 * @copyright  MIT License (c) 2020 Kushagra Agrawal and Kartik Venkat
 * @file  Utils.h
 * @brief Utils Class module
 * @author Kushagra Agrawal and Kartik Venkat
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

class Utils{
private:
    /**
  * @brief private variable for Classes.
  */
    std::vector<std::string> Classes;

    /**
     * @brief private variable for ClassesFile.
     */
    std::string classesFile="../coco.names";

    /**
     * @brief private variable for ModelConfigurationFile.
     */
    std::string modelConfigurationFile = "../yolov4.cfg";


    /**
     * @brief private variable for ModelWeightsFile.
     */
    std::string modelWeightsFile = "../yolov4.weights";

public:
    /**
     * @brief constructor for Utils class with no parameters.
     */
    Utils();

    /**
     * @brief It returns the ClassesFile.
     * @param None
     * @return std::string.
     */
    std::string getClassesFile();

    /**
     * @brief It sets the ClassesFile value.
     * @param ClassesValue (It is the path for the classes file.)
     * @return void.
     */
    void setClassesFile(const std::string&
                        classesValue);

    /**
     * @brief It returns the ModelConfiguration value.
     * @param None
     * @return std::string.
     */
    std::string getModelConfiguration();

    /**
     * @brief It sets the modelConfiguration value.
     * @param ModelConfigurationValue (It is the file containing Yolov3 model configuration.)
     * @return void.
     */
    void setModelConfiguration(const std::string& modelConfiguration);

    /**
     * @brief It returns the ModelWeights value.
     * @param None
     * @return std::string.
     */
    std::string getWeights();

    /**
     * @brief It sets the ModelWeights value.
     * @param ModelWeightsValue (It is the file containing yolov3 weights.)
     * @return void.
     */
    void setWeights(const std::string& modelWeights);

    /**
     * @brief It adds classes in std::vector<std::string>.
     * @param None
     * @return void.
     */
    void setClasses();

    /**
     * @brief It returns classes of type std::vector<std::string>.
     * @param None
     * @return std::vector<std::string>.
     */
    std::vector<std::string> getClasses();

    /**
     * @brief Destructor for Utils Class
     */
     ~Utils();
};

