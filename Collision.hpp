#ifndef H_COLLISION
#define H_COLLISION

#include "Map.hpp"
#include "Tile.hpp"

struct CollisionResult {
	float dx;
	float dy;
	bool floor;
	bool ceil;
	bool left;
	bool right;
};

class Collision {

public:

	Collision(Map* map) : _map(map) {}

	bool collide(sf::Sprite& obj, float dx, float dy, CollisionResult& result);


private:

  Map* _map;

};

#endif
