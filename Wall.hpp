#ifndef _WALL_
#define _WALL_

#include "Tile.hpp"

class Wall : public Tile {

public:
	inline bool isWalkable() { return false; }

	Wall(unsigned image) : Tile(image) {}

};


#endif
