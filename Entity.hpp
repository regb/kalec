#ifndef _ENTITY_
#define _ENTITY_

#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite {

public:

	Entity(unsigned int pvMax, float vx);

	virtual void act(float elapsedTime) = 0;
	void jump();
	void fall();
  void land();

  inline bool air() {
    return _air;
  }
	//void move();

protected:

	const unsigned int _pvMax;
	unsigned int _pv;
	float _vx, _vy;
  bool _air;

};

#endif
