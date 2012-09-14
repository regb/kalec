#ifndef _COLLISION_
#define _COLLISION_

#include "Map.hpp"
#include "Tile.hpp"

class Collision {

public:

	Collision(Map* map) : _map(map) {}

	bool collide(sf::Sprite& obj, float dx, float dy, bool& floor);


private:

  Map* _map;

};

#endif
