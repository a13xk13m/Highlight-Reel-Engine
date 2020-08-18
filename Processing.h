#pragma once
#include "opencv2/imgproc.hpp"
#include "Game.h"
// All methods used to process the video, including filters.

// Crops a frame based on coordinates given to a game object and returns a new Mat.
cv::Mat cropFrame(cv::Mat& frame, Coords& coords);
