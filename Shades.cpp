//
// Created by Evan Wieland on 11/12/21.
//

#include "Shades.h"
#include "Paint.h"

void Shades::draw(cv::Mat frame, float x, float y, float w)
{
    cv::Mat &i = img;
    Paint::drawTransparency(frame, resize(img, w), x, y);
}
