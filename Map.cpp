#include <iostream>
#include <SFML/Graphics.hpp>

#include "Map.hpp"
#include "WalkableTile.hpp"
#include "Wall.hpp"

void Map::load(std::istream& in) {
	std::cout << "Loading map" << std::endl;

	unsigned int width;
	unsigned int height;
	in >> width;
	//assert(width > 0);
	in >> height;
	//assert(height > 0);

	std::cout << "width: " << width << ", height: " << height << std::endl;

	map.reserve(height);

	for(unsigned i = 0; i < height; ++i) {
		std::vector<Tile*> row;
		row.reserve(width);
		for(unsigned j = 0; j < width; ++j) {
			int tileId;
			in >> tileId;
			if(tileId == 0)
				row.push_back(new WalkableTile());
			else
				row.push_back(new Wall());
			row.back()->SetX(j*32);
			row.back()->SetY(i*32);
			//assert row[j] == 
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
