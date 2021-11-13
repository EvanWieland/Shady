//
// Created by Evan Wieland on 11/9/21.
//

#include <opencv2/imgproc.hpp>
#include "Glasses.h"
#include "Paint.h"

void Glasses::draw(cv::Mat frame, float x, float y, float w)
{
    cv::Mat &i = img;
    Paint::drawTransparency(frame, resize(i, w), x, y);
}
