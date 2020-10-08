#include "Output.h"
// Constructor takes a reference to a video.
Output::Output(cv::VideoCapture* capture) {
	this->cap = capture;
}
//Trims the video and then outputs it to a seperate file.
bool Output::trimVideo(int startFrame, int frameCount, int vidIndex, std::string outputPath) {
	double fps = this->cap->get(cv::CAP_PROP_FPS);
	int width = (int)this->cap->get(cv::CAP_PROP_FRAME_WIDTH);
	int height = (int)this->cap->get(cv::CAP_PROP_FRAME_HEIGHT);
	int totalFrames = (int)this->cap->get(cv::CAP_PROP_FRAME_COUNT);
	cv::Size imgSize;
	imgSize.width = width;
	imgSize.height = height;
	int lenSeconds = 2;
	int framesToClip = (int)(lenSeconds * fps);
	double currFrame = 0;
	double stride = 2;
	// Open output video files        
	cv::VideoWriter vidwriter;
	int codec = cv::VideoWriter::fourcc('X', '2', '6', '4');
	std::string vidName(outputPath + "clip_" + std::to_string(vidIndex) + ".mp4");
	vidwriter.open(vidName, codec, fps, imgSize, true);
	if (!vidwriter.isOpened())
	{
		fprintf(stderr, "Could not open an output video file for write\n");
		return false;
	}

	// Extract subset of frames
	cv::Mat frame;
	// Set capture to the starting index
	cap->set(cv::CAP_PROP_POS_FRAMES, startFrame);
	for (int frameInd = startFrame; frameInd < startFrame + frameCount; ++frameInd)
	{
		*cap >> frame;
		if (frame.empty())
			break;
		vidwriter.write(frame);
	}
	vidwriter.release();
	// Set video back to where it was left.
	cap->set(cv::CAP_PROP_POS_FRAMES, startFrame + frameCount);
	return true;
}