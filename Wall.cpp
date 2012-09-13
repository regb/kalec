#include <SFML/Graphics.hpp>

#include "Globals.hpp"
#include "Wall.hpp"

Wall::Wall() {
	SetImage(imageManager.getWall());
}
