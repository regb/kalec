#include <cassert>
#include <iostream>

#include "Collision.hpp"
#include "constants.hpp"

bool Collision::collide(sf::Sprite& obj, float dx, float dy, CollisionResult& result) {
	std::cout << "dx: " << dx << std::endl;
	std::cout << "dy: " << dy << std::endl;

	result.side = false;
	result.floor = false;
	result.dx = dx;
	result.dy = dy;
	
	if(dx != 0.f) { //if moving horizontal

		bool left = dx < 0;

		float forwardX;
		if(left)
			forwardX = obj.GetPosition().x;
		else
			forwardX = obj.GetPosition().x + obj.GetSize().x;
		float newX = forwardX + dx;

		Tile* topTileX = _map->tileFromPixel(newX, obj.GetPosition().y + 1.f);
		Tile* botTileX = _map->tileFromPixel(newX, obj.GetPosition().y + obj.GetSize().y - 1.f);

		if(!topTileX->isWalkable() || !botTileX->isWalkable()) {
			result.side = true;
			float limit;
			if(left)
				limit = topTileX->GetPosition().x + topTileX->GetSize().x;
			else
				limit = topTileX->GetPosition().x;

			result.dx = limit - forwardX;
		}

		assert(left  || result.dx <= dx);
		assert(!left || result.dx >= dx);
	}

	float objPosX = obj.GetPosition().x + result.dx;
	if(dy != 0.f) { //if moving vertically
		bool down = dy > 0;

		float forwardY;
		if(down)
			forwardY = obj.GetPosition().y + obj.GetSize().y;
		else
			forwardY = obj.GetPosition().y;

		float newY = forwardY + dy;

		Tile* leftTileY = _map->tileFromPixel(objPosX + 1.f, newY);
		Tile* rightTileY = _map->tileFromPixel(objPosX + obj.GetSize().x - 1.f, newY);

		if(!leftTileY->isWalkable() || !rightTileY->isWalkable()) {
			result.floor = true;
			float limit;
			if(down)
				limit = leftTileY->GetPosition().y;// - constants::COLLISION_MARGIN;
			else
				limit = leftTileY->GetPosition().y + leftTileY->GetSize().y;// + constants::COLLISION_MARGIN;

			result.dy = limit - forwardY;
		}

		assert(down  || result.dy >= dy);
		assert(!down || result.dy <= dy);
	}

	return result.floor || result.side;
}
