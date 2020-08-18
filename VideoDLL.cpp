#include "VideoDLL.h"
#include "Video.h"

// Implementation of DLL exposed methods.
namespace VideoProc {
	// Exposes video processing method out of DLL.
	void VideoFuncs::processVideo(std::string filePath, std::string name, std::string game, std::string aspect) {
		cv::VideoCapture* cap = new cv::VideoCapture(filePath);
		Game g(game, aspect);
		Video::processVideo(cap, g, name);
	}
}