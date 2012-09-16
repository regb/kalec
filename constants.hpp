#ifndef _CONSTANTS_
#define _CONSTANTS_

namespace constants {
	const float GRAVITY = 400.f;
	const float AIR_FRICTION = 100.f;
	const float COLLISION_MARGIN = 0.001f;
	const unsigned TILE_WIDTH = 32;
	const unsigned TILE_HEIGHT = 32;
	const unsigned WINDOW_WIDTH = 10;
	const unsigned WINDOW_HEIGHT = 10;
	const sf::IntRect TILE_RECT(0, 0, TILE_WIDTH, TILE_HEIGHT);
}

#endif
