#include <iostream>

#include "ImageManager.hpp"

std::vector<sf::Image> ImageManager::images;

unsigned ImageManager::loadImage(const std::string& filename) {
	images.reserve(20); //TODO, caching that cannot be moved into another place in memory
  unsigned id = images.size();
	sf::Image image;
	if(!image.LoadFromFile(filename)) {
		std::cerr << "Cannot open resource: " << filename << std::endl;
		exit(-1);
	}
	images.push_back(image);
	return id;
}

sf::Image& ImageManager::getImage(unsigned id) {
	return ImageManager::images[id];
}

