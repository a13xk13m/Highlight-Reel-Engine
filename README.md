# Highlight Reel Engine
Highlight Reel Engine is designed to be the backend of a GUI that automatically trims video game clips
to produce smaller videos that are easier to share. Built using MSVC, executables will be provided soon.
## Goals
The goals of this tool is to provide a framework and implementation to allow for different games with different
gameplay highlights to be easily implemented into the engine and allow anyone to increase the capabilities of the
software.
## How To Add a Game
To add support for a game, create a new entry in the initCoordData() function in Game.cpp. For a new game, create
a new unordered map with the key being the name of the game and the value being a Coords object. The width/height
and x/y work as coefficients to work with varying resolutions. Siege is currently implemented and can be easily followed.

