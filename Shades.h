//
// Created by Evan Wieland on 11/12/21.
//

#ifndef SHADY_SHADES_H
#define SHADY_SHADES_H

#include <string>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include "Shape.h"
#include "File.h"

class Shades : public Shape
{
public:
    Shades()
    {
        img = imread(File::getCWD() + "/assets/sg2.png", cv::IMREAD_UNCHANGED);
    }

    void draw(cv::Mat frame, float x, float y, float w) override;

private:
    cv::Mat img;
};

#endif //SHADY_SHADES_H
