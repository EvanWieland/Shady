//
// Created by Evan Wieland on 11/9/21.
//

#ifndef SHADY_OBSERVER_H
#define SHADY_OBSERVER_H

#include "opencv2/objdetect.hpp"
#include "opencv2/face.hpp"

class Observer
{
public:
    void start();

private:
    void stream();
    cv::CascadeClassifier faceDetection;
    cv::Ptr <cv::face::Facemark> facemark;
};

#endif //SHADY_OBSERVER_H
