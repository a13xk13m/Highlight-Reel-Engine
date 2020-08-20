#include "Game.h"

// Coordinate struct constructor.
Coords::Coords(int x, int y, int w, int h) : _x(x), _y(y), _w(w), _h(h) {}

// Accessor functions.
int Coords::getX() {
	return this->_x;
}

int Coords::getY() {
	return this->_y;
}

int Coords::getW() {
	return this->_w;
}

int Coords::getH() {
	return this->_h;
}

// Constructor
Game::Game() {
	this->initCoordData(1920, 1080);
};

// Updates the killfeed coordinates.
void Game::updateKFCoords(Coords& coords) {
	this->kfCoords = coords;
}

// Initializes all game coordinate data.
void Game::initCoordData(int x, int y) {
	// Initialize siege aspect ratios.
	// Decimal values are relative values of kill feed location in order to support
	// multiple resolutions.
	std::unordered_map < std::string, Coords > siegeAspectRatios = {
		{"4:3", Coords(0.78125 * x, 0.33796 * y, 0.20833 * x, 0.02314 * y)}
	};

	this->mapping.insert(std::pair<std::string, std::unordered_map<std::string, Coords>>("siege", siegeAspectRatios));
}

// Creates a game object with the correct coordinates.
Game::Game(std::string game, std::string aspect, int x, int y) {
	this->initCoordData(x, y);
	// Goes through the mapping and sets the proper coordinates.
	this->kfCoords = this->mapping.at(game).at(aspect);
}

// Returns the killfeed coordinates.
Coords Game::KFCoords() {
	return this->kfCoords;
}
