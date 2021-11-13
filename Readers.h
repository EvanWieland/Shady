//
// Created by Evan Wieland on 11/13/21.
//

#ifndef SHADY_READERS_H
#define SHADY_READERS_H

#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include "Readers.h"
#include "File.h"

class Readers
{
    Readers()
    {
        readers = imread(File::getCWD() + "/assets/rg.png", cv::IMREAD_UNCHANGED);
    }

private:
    cv::Mat readers;
};

#endif //SHADY_READERS_H
