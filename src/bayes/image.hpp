//
//  image.hpp
//  fantastic-finale-seunghoon0821
//
//  Created by SeungHoon Choi on 12/5/19.
//
#pragma once

#ifndef image_hpp
#define image_hpp

#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <iostream>
#include "ofxCv.h"

constexpr size_t IMAGE_SIZE = 28;
const int NUM_TRAINING_IMAGES = 2400;
const int NUM_FONTS = 100;

struct Image {
    char pixels[IMAGE_SIZE][IMAGE_SIZE];

    std::vector<std::string> image;
    // What Korean character the image is.
    std::string classification;

};

/**
 * Creates an image with each pixel changed to 0 or 1 depending on whether or not its unshaded or not, respectively.
 * @param data_labels The path to the label text file.
 * @param images_directory_path The directory with all images that will be looped through.
 * @param dataset Vector of Images.
 * @param num The number of occurences of a certain label in the images directory.
 */
void ImageVector(std::string data_labels, std::string images_directory_path, std::vector<Image> &dataset, int num);

/**
 * Computes the prior probability (# of occurences for a certain class / # of all images)
 * @param occurrences The number of occurences for a certain class
 * @return The prior probability for a specific class.
 */
double ComputePriors(double occurrences);


#endif /* image_hpp */
