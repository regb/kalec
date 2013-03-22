#ifndef H_ENTITY
#define H_ENTITY

#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite {

public:

	Entity(unsigned int pvMax);

	virtual void act(float elapsedTime) = 0;

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
