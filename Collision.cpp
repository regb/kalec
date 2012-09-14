#include <cassert>
#include <iostream>

#include "Collision.hpp"

bool Collision::collide(sf::Sprite& obj, float dx, float dy, bool& floor) {

	float topLeftX = obj.GetPosition().x + dx;
	float topLeftY = obj.GetPosition().y + dy;

	float topRightX = obj.GetPosition().x + obj.GetSize().x + dx;
	float topRightY = obj.GetPosition().y + dy;

	float botLeftX = obj.GetPosition().x + dx;
	float botLeftY = obj.GetPosition().y + obj.GetSize().y + dy;

	float botRightX = obj.GetPosition().x + obj.GetSize().x + dx;
	float botRightY = obj.GetPosition().y + obj.GetSize().y + dy;

	Tile* topLeft = _map->tileFromPixal(topLeftX, topLeftY);
	Tile* topRight = _map->tileFromPixal(topRightX, topRightY);
	Tile* botLeft = _map->tileFromPixal(botLeftX, botLeftY);
	Tile* botRight = _map->tileFromPixal(botRightX, botRightY);

	if(!botLeft->isWalkable() || !botRight->isWalkable())
		floor = true;
	else
		floor = false;

	assert(topLeft && topRight && botLeft && botRight);

	return floor || !topLeft->isWalkable() || !topRight->isWalkable();

}
