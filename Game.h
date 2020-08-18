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
		// Killfeed coordinates.
		Coords kfCoords;
		// Mapping of all games and aspect ratios.
		std::unordered_map<const char*, std::unordered_map<const char*, Coords>> mapping;
		// Initializes all aspect ratio and game mappings.
		void initCoordData();

	public:
		// Constructor.
		Game();
		// Constructor that takes a game and an aspect ratio and sets the coordinates.
		Game(std::string game, std::string aspect);
		// Updates the killfeed coords.
		void updateKFCoords(Coords& coords);
		// Returns the coordinates to the specific killfeed. Required for highlights to work.
		// Needs to be freed after.
		Coords KFCoords();
};

