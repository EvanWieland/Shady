//
// Created by Evan Wieland on 11/9/21.
//

#ifndef SHADY_PAINT_H
#define SHADY_PAINT_H

#include "opencv2/objdetect.hpp"
#include "Shape.h"
#include <vector>

class Paint
{
public:
    static void drawFromLandmarks(cv::Mat &frame, Shape &shape, std::vector<cv::Point2f> &landmarks);
    static void drawTransparency(cv::Mat &frame, cv::Mat alphaFrame, float x, float y);
};

#endif //SHADY_PAINT_H
