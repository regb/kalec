#ifndef _ENTITY_
#define _ENTITY_

#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite {

public:

	Entity(unsigned int pvMax) : _pvMax(pvMax), _pv(pvMax) {}

	virtual void act() = 0;

private:

	const unsigned int _pvMax;
	unsigned int _pv;

};

#endif
