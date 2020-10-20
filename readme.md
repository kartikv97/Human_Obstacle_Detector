# Human Obstacle Detector
[![Build Status](https://travis-ci.org/kushagra7176/Human_Obstacle_Detector.svg?branch=master)](https://travis-ci.org/kushagra7176/Human_Obstacle_Detector)
[![Coverage Status](https://coveralls.io/repos/github/kushagra7176/Human_Obstacle_Detector/badge.svg?branch=master)](https://coveralls.io/github/kushagra7176/Human_Obstacle_Detector?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/kushagra7176/Human_Obstacle_Detector/blob/master/LICENSE)
---

## Authors
Currently pursuing M.Eng in Robotics from University of Maryland, College Park.
- Kushagra Agrawal - B.Tech in Mechanical Engineering from Manipal Insttitute of Technology.
- Kartik Venkat - B.Tech in Electronics and Telecommunication Engineering from SIES Graduate School of Technology, Mumbai.

## AIP Document
[![AIP](https://img.shields.io/badge/AIP-Click%20Here-red)](https://docs.google.com/spreadsheets/d/1zLw-v8QNDz0xUzbNKgPRX_UwlmFRW5TeJ5RUZ21CM4s/edit#gid=0)

## Overview
The autonomous navigation of a robot or an agent in an environment or a scene is the most talked about problem in the autonomous industry nowadays. If an agent wants to navigate autonomously in an environment it should be able to detect and avoid all kinds of obstacles which come in its way. 

In this project we are developing a real time object detection and avoidance classifier using YOLO v3 for ACME Robotics. The output given by our module can be used by the Path Planning module of the system to design a path avoiding all the obstacles detected by our module. We plan on using a YOLO v3 object detection algorithm. The external library that will be used is openCV. We are also going to use the pre-trained model of YOLO v3 which is already present in the openCV library.

## Standard install via command-line
```
git clone --recursive https://github.com/kushagra7176/Human_Obstacle_Detector
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/kushagra7176/Human_Obstacle_Detector
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of Human_Obstacle_Detector

```
cd ~/workspace
mkdir -p HumanObstacleDetector
cd HumanObstacleDetector
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../Human_Obstacle_Detector/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "HumanObstacleDetector" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold HumanObstacleDetector project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the HumanObstacleDetector in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)

