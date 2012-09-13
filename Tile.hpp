#ifndef _TILE_
#define _TILE_

#include <SFML/Graphics.hpp>

class Tile : public sf::Sprite {

public:

  virtual bool isWalkable() = 0;

};

#endif
