#include <cassert>

#include "Entity.hpp"

Entity::Entity(unsigned int pvMax) : 
  sf::Sprite(), _pvMax(pvMax), _pv(pvMax), _vx(0), _vy(0), _air(true) {
    
}

void Entity::jump() {
  _vy = -10.;
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
