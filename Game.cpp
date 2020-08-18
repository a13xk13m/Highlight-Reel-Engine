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
	this->initCoordData();
};

// Updates the killfeed coordinates.
void Game::updateKFCoords(Coords& coords) {
	this->kfCoords = coords;
}

// Initializes all game coordinate data.
void Game::initCoordData() {
	// Initialize siege aspect ratios.
	std::unordered_map < const char*, Coords > siegeAspectRatios = {
		{"4:3", Coords(1500, 365, 400, 25)}
	};

	this->mapping.insert(std::pair<const char*, std::unordered_map<const char*, Coords>>("siege", siegeAspectRatios));
}

// Creates a game object with the correct coordinates.
Game::Game(std::string game, std::string aspect) {
	this->initCoordData();
	// Goes through the mapping and sets the proper coordinates.
	this->kfCoords = this->mapping.at(game.c_str()).at(aspect.c_str());
}

// Returns the killfeed coordinates.
Coords Game::KFCoords() {
	return this->kfCoords;
}
