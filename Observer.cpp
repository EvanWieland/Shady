//
// Created by Evan Wieland on 11/9/21.
//

#include "Observer.h"
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/face.hpp"
#include <iostream>
#include "Paint.h"
#include "Glasses.h"
#include "Shades.h"
#include "File.h"

using namespace cv;
using namespace cv::face;
using namespace std;

enum class Spectacles
{
    SHADES, GLASSES
};

void Observer::start()
{
    // Load the face detection cascade
    if (!faceDetection.load(File::getCWD() + "/assets/haarcascade_face.xml")) {
        cout << "Face detection cascade classifier not loaded" << endl;
        exit(0);
    }

    // Create an instance of Facemark
    facemark = FacemarkLBF::create();

    // Load landmark detector
    facemark->loadModel(File::getCWD() + "/assets/lbfmodel.yml");

    // Begin video stream and face detecting
    stream();
}

void Observer::stream()
{
    // Start video stream
    VideoCapture cap(0);

    // Construct frames
    Mat frame, gray;

    // Set default specs to GLASSES
    Spectacles specs = Spectacles::GLASSES;

    // Init spectacle classes
    Glasses glasses;
    Shades shades;

    // View frame from video stream
    while (cap.read(frame)) {
        vector<Rect> faces;

        // Convert frame to grayscale for better results
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Do face detection
        faceDetection.detectMultiScale(gray, faces);

        // Vector of vectors containing face landmarks
        vector<vector<Point2f> > landmarks;

        // Run landmark detector on the detected faces
        bool detected = facemark->fit(frame, faces, landmarks);

        if (detected) {
            // Draw spectacles for each detected face
            for (int i = 0; i < landmarks.size(); i++) {

                // Draw based on landmarks... a little polymorphism magic here.
                if (specs == Spectacles::SHADES) {
                    Paint::drawFromLandmarks(frame, shades, landmarks[i]);
                } else {
                    Paint::drawFromLandmarks(frame, glasses, landmarks[i]);
                }
            }
        }

        // Display results
        imshow("Spectacle Augmentation", frame);

        // Swap between glasses and shades if ENTER key is pressed
        if (waitKey(1) == 13)
            specs == Spectacles::SHADES ? specs = Spectacles::GLASSES : specs = Spectacles::SHADES;

        // Exit if ESC key is pressed
        if (waitKey(1) == 27) break;
    }
}