#include "ImageManager.hpp"

ImageManager::ImageManager() {
	if(!_wall.LoadFromFile("wall.png")) {
		exit(-1);
	}
	if(!_grass.LoadFromFile("grass.png")) {
		exit(-1);
	}
}
