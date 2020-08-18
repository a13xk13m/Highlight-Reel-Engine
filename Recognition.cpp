#include "Recognition.h"
#include <opencv2\imgproc.hpp>

// Constructor creates a new Tesseract object.
Recognition::Recognition() {
	this->api = new tesseract::TessBaseAPI();
	this->api->Init(NULL, "eng");
}

// Recognizes text in a frame and returns the text.
std::string Recognition::recText(cv::Mat& img)
{
	cv::Mat imgGrey;
	cv::cvtColor(img, imgGrey, cv::COLOR_BGR2GRAY);
	// Initialize tesseract-ocr with English, without specifying tessdata path
	if (api->Init(NULL, "eng")) {
		fprintf(stderr, "Could not initialize tesseract.\n");
		exit(1);
	}

	api->SetImage((uchar*)img.data, img.size().width, img.size().height, img.channels(), img.step1());
	const char* out = api->GetUTF8Text();
	std::string text = out;
	delete[] out;
	return text;
}

// Destructor.
Recognition::~Recognition() {
	this->api->End();
}