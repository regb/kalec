#include <iostream>
#include <cassert>
#include <SFML/Graphics.hpp>

#include "Map.hpp"
#include "WalkableTile.hpp"
#include "Wall.hpp"
#include "ImageManager.hpp"

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

	map.reserve(height);

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
			row.back()->SetX(j*32);
			row.back()->SetY(i*32);
			assert(row[j] == row.back());
		}
		map.push_back(row);
	}

}

void Map::render(sf::RenderWindow& app) {
	for(unsigned i = 0; i < map.size(); ++i) {
		for(unsigned j = 0; j < map[i].size(); ++j) {
			app.Draw(*map[i][j]);
		}
	}
}

Tile*& Map::tile(unsigned int i, unsigned int j) {
	assert(i < map.size());
	assert(j < map[i].size());
	return map[i][j];
}

//let's just assume that if 32 ~| x then it could return any of the two tile
Tile*& Map::tileFromPixel(float x, float y) {
	assert(x >= 0);
	assert(y >= 0);
  unsigned int xi = int(x/32.f);
  unsigned int yi = int(y/32.f);
	assert(xi < map.size());
	assert(yi < map[xi].size());
	//std::cout << "tileFromPixel\n";
	//std::cout << "x: " << x << ", y: " << y << std::endl;
	//std::cout << "xi: " << xi << ", yi: " << yi << std::endl;
	return map[yi][xi];
}
