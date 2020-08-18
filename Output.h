#pragma once
#include <opencv2\videoio.hpp>

// Class that can trim video and output to a new file.
class Output {
	private:
		cv::VideoCapture* cap;
	public:
		// Constructor takes a reference to the target video that will be trimmed.
		Output(cv::VideoCapture* capture);
        //Trims the video and then outputs it to a seperate file.
		bool trimVideo(int startFrame, int frameCount, int vidIndex);
};