#include "opencv2/videoio.hpp"
// Code responsible for loading video into program. 
// Simple import only currently supported.

// Opens the video and returns a pointer to the VideoCapture object.
// Needs to be freed when done.
cv::VideoCapture* openVideo(std::string filename) {
    cv::VideoCapture* cap = new cv::VideoCapture(filename);
    // Check to see if video works.
    if (!cap->isOpened()) {
        throw "Video couldn't be opened.";
    }
    return cap;
}