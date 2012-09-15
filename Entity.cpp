#include <cassert>

#include "Entity.hpp"

Entity::Entity(unsigned int pvMax) : 
  sf::Sprite(), _pvMax(pvMax), _pv(pvMax), _vx(0), _vy(0), _air(true) {
    
}
