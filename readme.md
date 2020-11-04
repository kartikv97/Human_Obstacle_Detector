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

## Video Submission
[![Phase1](https://img.shields.io/badge/Phase1-Click%20Here-red)](https://drive.google.com/drive/folders/1g6_zxrTMXEDqJOSKTqIsP0zMl6BQq-Ac?usp=sharing)
[![Phase2](https://img.shields.io/badge/Phase2-Click%20Here-red)](https://drive.google.com/drive/folders/1xGAmPG-Q1KaeIRgmRHxzmrEk4wp_5rR7?usp=sharing)


## Overview
The autonomous navigation of a robot or an agent in an environment or a scene is the most talked about problem in the autonomous industry nowadays. If an agent wants to navigate autonomously in an environment it should be able to detect and avoid all kinds of obstacles which come in its way. 

In this project we are developing a real time object detection and avoidance classifier using YOLO v3 for ACME Robotics. The output given by our module can be used by the Path Planning module of the system to design a path avoiding all the obstacles detected by our module. We plan on using a YOLO v3 object detection algorithm. The external library that will be used is openCV. We are also going to use the pre-trained model of YOLO v3 which is already present in the openCV library.

## Standard install via command-line
```
git clone --recursive https://github.com/kushagra7176/Human_Obstacle_Detector
cd <path to repository>
bash requirements.sh
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app --image=../dog.jpg ( use --show_output if you want to display the output )
                                                ( use --video=../pedestrians.mp4 to run demo on video )
```
