#ifndef _TILE_
#define _TILE_

#include <SFML/Graphics.hpp>

class Tile : public sf::Sprite {

public:

  Tile(unsigned image);

  virtual bool isWalkable() = 0;

private:

  unsigned _image;

};

#endif
