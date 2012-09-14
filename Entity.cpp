#include <cassert>

#include "Entity.hpp"

void Entity::jump() {
  if(!_air) {
		_vy = -50;
    _air = true;
	} //else we are already in the air so we cannot jump
}

void Entity::land() {
  assert(_air);
  _air = false;
  _vy = 0;
}
