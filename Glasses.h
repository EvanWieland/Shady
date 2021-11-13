//
// Created by Evan Wieland on 11/9/21.
//

#ifndef SHADY_GLASSES_H
#define SHADY_GLASSES_H

#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include "Shape.h"
#include "File.h"

class Glasses : public Shape
{
public:
    Glasses()
    {
        img = imread(File::getCWD() + "/assets/g.png", cv::IMREAD_UNCHANGED);
    }

    void draw(cv::Mat frame, float x, float y, float w) override;
private:
    cv::Mat img;
};

#endif //SHADY_GLASSES_H
