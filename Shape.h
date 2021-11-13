//
// Created by Evan Wieland on 11/13/21.
//

#ifndef SHADY_SHAPE_H
#define SHADY_SHAPE_H

#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>

class Shape
{
public:
    Shape()
    {
    }

    cv::Mat resize(const cv::Mat &input, float w);

    virtual void draw(cv::Mat frame, float x, float y, float w);

private:
};

#endif //SHADY_SHAPE_H
