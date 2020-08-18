#include "Video.h"
#include "Output.h"
#include "Processing.h"
#include "Recognition.h"
#include <opencv2\videoio.hpp>
#include <iostream>
namespace Video {
    // Determines if one string contains another.
    bool charContains(std::string toFind, std::string rawStr) {
        std::transform(toFind.begin(), toFind.end(), toFind.begin(), ::tolower);
        std::transform(rawStr.begin(), rawStr.end(), rawStr.begin(), ::tolower);
        if (rawStr.find(toFind) != std::string::npos)
            return true;
        else
            return false;
    }

    // Video processing and trimming.
    void processVideo(cv::VideoCapture* video, Game& game, std::string name) {
        Recognition r = Recognition();
        // Video information
        double fps = video->get(cv::CAP_PROP_FPS);
        int width = (int)video->get(cv::CAP_PROP_FRAME_WIDTH);
        int height = (int)video->get(cv::CAP_PROP_FRAME_HEIGHT);
        int totalFrames = (int)video->get(cv::CAP_PROP_FRAME_COUNT);
        // Output file information
        Output o = Output(video);
        Coords kf = game.KFCoords();
        int lenSeconds = 5;
        int framesToClip = (int)(lenSeconds * fps);
        double currFrame = 0;
        double stride = 10;
        int vidIndex = 0;
        while (currFrame < totalFrames - 1) {
            double totalFrames = (fps * lenSeconds);
            double startFrame = (currFrame - framesToClip);
            if (startFrame < 0) {
                startFrame = 0;
            }
            video->set(cv::CAP_PROP_POS_FRAMES, currFrame);
            cv::Mat frame;
            // Capture frame-by-frame
            *video >> frame;
            // If the frame is empty, break immediately
            if (frame.empty()) {
                break;
            }

            // Setup a rectangle to define your region of interest
            cv::Mat crop = cropFrame(frame, kf);
            std::string s = r.recText(crop);
            bool nameFound = charContains(name, s);
            std::cout << s << std::endl;
            std::cout << nameFound << std::endl;
            std::cout << startFrame << std::endl;
            if (nameFound) {
                o.trimVideo(startFrame, 120, vidIndex);
                vidIndex++;
            }
            crop.release();
            currFrame += stride;
        }
    }
}