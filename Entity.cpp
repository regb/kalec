#include <cassert>

#include "Entity.hpp"

Entity::Entity(unsigned int pvMax, float vx) : 
  sf::Sprite(), _pvMax(pvMax), _pv(pvMax), _vx(vx), _vy(50), _air(true) {
    
}

void Entity::jump() {
  if(!_air) {
		_vy = -50;
    _air = true;
	} //else we are already in the air so we cannot jump
}

void Entity::fall() {
  assert(!_air);
  _vy = 50;
  _air = true;
}

void Entity::land() {
  assert(_air);
  _air = false;
  _vy = 0;
}
