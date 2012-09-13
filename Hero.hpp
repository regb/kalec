#ifndef _HERO_
#define _HERO_

#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Hero : public Entity {

public:
	Hero(unsigned int pvMax);

	void act();

};

#endif
