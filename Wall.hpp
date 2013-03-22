#ifndef H_WALL
#define H_WALL

#include "Tile.hpp"

class Wall : public Tile {

public:
	inline bool isWalkable() { return false; }

	Wall(unsigned image) : Tile(image) {}

};


#endif
