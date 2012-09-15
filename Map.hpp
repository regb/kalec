#ifndef _MAP_
#define _MAP_

#include <istream>
#include <SFML/Graphics.hpp>

#include "Tile.hpp"

class Map {

public:
  Tile*& tile(unsigned int i, unsigned int j);
	Tile*& tileFromPixel(float x, float y);

	Map() {}

	void load(std::istream& in);

	void render(sf::RenderWindow& app);
   
private:

  std::vector< std::vector< Tile* > > map;

};

#endif
