#ifndef _WALKABLETILE_
#define _WALKABLETILE_

#include "Tile.hpp"

class WalkableTile: public Tile {

public:
	inline bool isWalkable() { return true; }

	WalkableTile(unsigned image) : Tile(image) {}

private:

};


#endif
