#include "Tile.hpp"
#include "ImageManager.hpp"

Tile::Tile(unsigned image) : _image(image) {
	SetImage(ImageManager::getImage(image));
}
