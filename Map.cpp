#include <iostream>
#include <cassert>
#include <SFML/Graphics.hpp>

#include "Map.hpp"
#include "WalkableTile.hpp"
#include "Wall.hpp"
#include "ImageManager.hpp"
#include "constants.hpp"

//TODO: force load in constructor
void Map::load(std::istream& in) {
	std::cout << "Loading map" << std::endl;

	unsigned grass = ImageManager::loadImage("grass.png");
	unsigned wall = ImageManager::loadImage("wall.png");

	unsigned int width;
	unsigned int height;
	in >> width;
	assert(width > 0);
	in >> height;
	assert(height > 0);

	std::cout << "width: " << width << ", height: " << height << std::endl;

	_map.reserve(height);

	for(unsigned i = 0; i < height; ++i) {
		std::vector<Tile*> row;
		row.reserve(width);
		for(unsigned j = 0; j < width; ++j) {
			int tileId;
			in >> tileId;
			if(tileId == 0)
				row.push_back(new WalkableTile(grass));
			else
				row.push_back(new Wall(wall));
			row.back()->SetX(j*constants::TILE_WIDTH);
			row.back()->SetY(i*constants::TILE_HEIGHT);
			assert(row[j] == row.back());
		}
		_map.push_back(row);
	}

	_height = _map.size();
	_width = _map[0].size();
	_sizeX = _width * constants::TILE_WIDTH;
	_sizeY = _height * constants::TILE_HEIGHT;
}

void Map::render(sf::RenderWindow& app) {
	unsigned minJ = _windowX/float(constants::TILE_WIDTH);
	unsigned minI = _windowY/float(constants::TILE_HEIGHT);
	unsigned maxJ = minJ + constants::WINDOW_WIDTH;
	unsigned maxI = minI + constants::WINDOW_HEIGHT;
	maxJ = (maxJ < _height)? maxJ : _height-1;
	maxI = (maxI < _width)? maxI : _width-1;
	for(unsigned i = minI; i <= maxI; ++i) {
		for(unsigned j = minJ; j <= maxJ; ++j) {
			app.Draw(*_map[i][j]);
		}
	}
}

//Tile*& Map::tile(unsigned int i, unsigned int j) {
//	assert(i < _map.size());
//	assert(j < _map[i].size());
//	return _map[i][j];
//}

Tile*& Map::tileFromPixel(float x, float y) {
	std::cout << "tileFromPixel\n";
	std::cout << "x: " << x << ", y: " << y << std::endl;
	assert(x >= 0);
	assert(y >= 0);
  unsigned int xi = int(x/float(constants::TILE_WIDTH));
  unsigned int yi = int(y/float(constants::TILE_HEIGHT));
	std::cout << "xi: " << xi << ", yi: " << yi << std::endl;
	assert(yi < _map.size());
	assert(xi < _map[yi].size());
	return _map[yi][xi];
}

void Map::setWidowCenter(float x, float y) {
  _windowX = x - (constants::WINDOW_WIDTH*constants::TILE_WIDTH/2);
  _windowY = y - (constants::WINDOW_HEIGHT*constants::TILE_HEIGHT/2);

	if(_windowX < 0)
		_windowX = 0;
	if(_windowY < 0)
		_windowY = 0;

	if(_windowX + constants::WINDOW_WIDTH*constants::TILE_WIDTH > _sizeX)
		_windowX = _sizeX - constants::WINDOW_WIDTH*constants::TILE_WIDTH;
	if(_windowY + constants::WINDOW_HEIGHT*constants::TILE_HEIGHT > _sizeY)
		_windowY = _sizeY - constants::WINDOW_HEIGHT*constants::TILE_HEIGHT;
}
