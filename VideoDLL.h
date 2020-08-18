#pragma once
#include <opencv2\videoio.hpp>
#include "Game.h"
// Exposes necessary functions in the DLL.

namespace VideoProc {
	class VideoFuncs {
	public:
		// Process video
		static __declspec(dllexport) void processVideo(std::string filePath, std::string name, std::string game, std::string aspect);
	};
}