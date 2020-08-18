#pragma once
#include <tesseract\baseapi.h>
#include <opencv2\core\mat.hpp>

// Class used to recognize text in a frame.
class Recognition {
    private:
        // Tesseract API object.
        tesseract::TessBaseAPI* api;
    public:
        // Constructor
        Recognition();
        // Recognizes the text in a frame.
        std::string recText(cv::Mat& img);
        // Destructor
        ~Recognition();
};