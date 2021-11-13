//
// Created by Evan Wieland on 11/9/21.
//

#include "Paint.h"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

// Color for augmentation points
#define COLOR Scalar(255, 200,0)

void Paint::drawFromLandmarks(Mat &frame, Shape &shape, vector<cv::Point2f> &landmarks)
{
    // Model has 68 points
    if (landmarks.size() == 68) {
        // Give the spectacles a little padding
        const float xAdjust = 50.0;
        const float yAdjust = 50.0;

        // Get left most eyebrow point
        const auto leftEyeBrow = landmarks[17];
        // Get right most eyebrow point
        const auto rightEyeBrow = landmarks[26];
        // Calculate width between eyebrow landmarks
        const auto browWidth = rightEyeBrow.x - leftEyeBrow.x;

        // Landmark points for left most brow and right most brow points (debugging)
//        cv::circle(frame, landmarks[17], 3, COLOR, FILLED);
//        cv::circle(frame, landmarks[26], 3, COLOR, FILLED);

        const float x = leftEyeBrow.x - (xAdjust / 2);
        const float y = leftEyeBrow.y - yAdjust;

        const int frameHeight = frame.size().height;
        const int frameWidth = frame.size().width;

        // Ensure image can fit in the frame to prevent out of bound exceptions
        if (
                (x > 0 && y > 0) &&
                (browWidth + x + xAdjust < frameWidth) &&
                (browWidth * .5 + y + yAdjust < frameHeight) &&
                (browWidth > 100) // Help reduce false positives
                ) {

            shape.draw(frame, x, y, browWidth + xAdjust);
        }
    }
}

// Draw a frame with an alpha channel onto another frame
void Paint::drawTransparency(Mat &frame, Mat alphaFrame, float x, float y)
{
    Mat mask;
    vector<Mat> layers;

    // I found this somewhere on StackOverflow, but can't remember where
    split(alphaFrame, layers);
    Mat rgb[3] = {layers[0], layers[1], layers[2]};
    mask = layers[3];
    merge(rgb, 3, alphaFrame);

    alphaFrame.copyTo(frame.rowRange(y, y + alphaFrame.rows).colRange(x, x + alphaFrame.cols), mask);
}
