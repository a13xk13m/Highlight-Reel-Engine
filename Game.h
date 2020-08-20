#pragma once
#include <unordered_map>
#include <string>

// Struct to hold coordinates of important objects on the screen.
struct Coords {
	private:
		int _x, _y, _w, _h;
	public:
		Coords() = default;
		Coords(int x, int y, int w, int h);

		// Accessor functions.
		int getX();

		int getY();

		int getW();

		int getH();
};

// Class to hold game specific data.
class Game {
	private:
		// Private, useless onstructor.
		Game();
		// Killfeed coordinates.
		Coords kfCoords;
		// Mapping of all games and aspect ratios.
		std::unordered_map<std::string, std::unordered_map<std::string, Coords>> mapping;
		// Initializes all aspect ratio and game mappings to the passed resolution.
		void initCoordData(int x, int w);

	public:
		// Constructor that takes a game and an aspect ratio and sets the coordinates based on the resolution.
		Game(std::string game, std::string aspect, int x, int y);
		// Updates the killfeed coords.
		void updateKFCoords(Coords& coords);
		// Returns the coordinates to the specific killfeed. Required for highlights to work.
		// Needs to be freed after.
		Coords KFCoords();
};

