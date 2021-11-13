//
// Created by Evan Wieland on 11/13/21.
//

#include <opencv2/imgproc.hpp>
#include "Shape.h"

void Shape::draw(cv::Mat frame, float x, float y, float w)
{
    cv::Rect rect(x, y, w, w);
    cv::rectangle(frame, rect, cv::Scalar(0, 255, 0));
}

// Resize an image and preserve ratio
cv::Mat Shape::resize(const cv::Mat &input, const float w)
{
    cv::Mat out;
    double scale = float(w) / input.size().width;
    cv::resize(input, out, cv::Size(input.cols * scale, input.rows * scale), 0, 0, cv::INTER_LINEAR);
    return out;
}
