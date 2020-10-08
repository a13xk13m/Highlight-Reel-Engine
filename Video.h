#pragma once
#include "Video.h"
#include "Processing.h"
#include "Recognition.h"
#include <opencv2\videoio.hpp>
#include "Output.h"

namespace Video {
	// Determines if one string contains another.
	bool charContains(std::string toFind, std::string rawStr);

	// Video processing and trimming.
	void processVideo(cv::VideoCapture* video, Game& game, std::string name, std::string outputPath);
}