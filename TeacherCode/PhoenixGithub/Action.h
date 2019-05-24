//
// Created by chelseaw on 01/05/17.
//

#ifndef IMAGE_EDITOR_ACTION_H_
#define IMAGE_EDITOR_ACTION_H_

#include <iostream>
#include <string>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/stitching.hpp"

using std::string;
using namespace cv;

class Action
{
public:
        Action(){}
        virtual void run(int pos, Mat& img, Mat& imgFactor)=0;
        virtual string description();
        ~Action(){}
};

#endif //IMAGE_EDITOR_ACTION_H
