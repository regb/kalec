#include "Entity.hpp"

void Entity::jump() {
  if(_vy == 0) {
		_vy = -50;
	} //else we are already in the air so we cannot jump
}

