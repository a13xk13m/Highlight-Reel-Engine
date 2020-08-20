#include <iostream>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include "Video.h"
#include "Game.h"

// Main loop
int main() {
    // Get the name of the file.
    std::string fileName;
    std::cout << "File name: ";
    std::cin >> fileName;
    std::cout << std::endl;
    cv::VideoCapture* cap = new cv::VideoCapture(fileName);
    // Get the username of the player.
    std::cout << "\nUsername to trim clips for: ";
    std::string username;
    std::getline(std::cin, username);
    std::cout << std::endl;
    std::string gameName;
    std::cout << "Game name ('siege'): ";
    std::cin >> gameName;
    std::cout << std::endl;
    std::string aspectRatio;
    std::cout << "Aspect ratio ('4:3'): ";
    std::cin >> aspectRatio;
    std::cout << std::endl;
    Game g(gameName, aspectRatio, 1920, 1080);
    Video::processVideo(cap, g, username);
}