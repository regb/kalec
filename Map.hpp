#ifndef _MAP_
#define _MAP_

#include <istream>
#include <SFML/Graphics.hpp>

#include "Tile.hpp"
#include "constants.hpp"

class Map {

public:
  //Tile*& tile(unsigned int i, unsigned int j);
	Tile*& tileFromPixel(float x, float y);

	Map(): _windowX(0), _windowY(0) {}

	void load(std::istream& in);

	void render(sf::RenderWindow& app);

	inline sf::FloatRect window() {
		return sf::FloatRect(
			_windowX, 
			_windowY, 
			_windowX + constants::WINDOW_WIDTH*constants::TILE_WIDTH, 
			_windowY + constants::WINDOW_HEIGHT*constants::TILE_HEIGHT);
	}

	void setWidowCenter(float x, float y);
   
private:

  std::vector< std::vector< Tile* > > _map;

	float _windowX, _windowY;
	float _sizeX, _sizeY;
	unsigned _height, _width;

};

#endif
