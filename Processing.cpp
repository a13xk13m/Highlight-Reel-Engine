#include "Processing.h"
#include "opencv2/imgproc.hpp"
#include "Game.h"
// All methods used to process the video, including filters.

// Crops a frame based on coordinates given to a game object and returns a new Mat.
cv::Mat cropFrame(cv::Mat& frame, Coords& coords) {
    cv::Mat crop;
    cv::Rect rect(coords.getX(), coords.getY(),
        coords.getW(), coords.getH());
    crop = frame(rect);
    return crop;
}
