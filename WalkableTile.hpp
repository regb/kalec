#ifndef H_WALKABLETILE
#define H_WALKABLETILE

#include "Tile.hpp"

class WalkableTile: public Tile {

public:
	inline bool isWalkable() { return true; }

	WalkableTile(unsigned image) : Tile(image) {}

private:

};


#endif
