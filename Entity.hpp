#ifndef _ENTITY_
#define _ENTITY_

#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite {

public:

	Entity(unsigned int pvMax, float vx) : sf::Sprite(), _pvMax(pvMax), _pv(pvMax), _vx(vx) {}

	virtual void act(float elapsedTime) = 0;
	void jump();
	//void move();

protected:

	const unsigned int _pvMax;
	unsigned int _pv;
	float _vx, _vy;

};

#endif
