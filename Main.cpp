#include <iostream>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include "Video.h"
#include "Game.h"

// Main loop
// Arguments, in order: filepath, outputpath username, name of game, aspect ratio, width, height
int main(int argc, char** argv) {
    // Get the name of the file.
    std::string fileName = argv[1];
    std::string outputPath = argv[2];
    std::string username = argv[3];
    std::string gameName = argv[4];
    std::string aspectRatio = argv[5];
    cv::VideoCapture* cap = new cv::VideoCapture(fileName);
    Game g(gameName, aspectRatio, atoi(argv[6]), atoi(argv[7]));
    Video::processVideo(cap, g, username, outputPath);
}