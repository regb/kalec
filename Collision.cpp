#include <cassert>
#include <iostream>

#include "Collision.hpp"
#include "constants.hpp"

bool Collision::collide(sf::Sprite& obj, float dx, float dy, CollisionResult& result) {
	//assert(_map->tileFromPixel(obj.GetPosition().x, obj.GetPosition().y)->isWalkable());
	//assert(_map->tileFromPixel(obj.GetPosition().x + obj.GetSize().x, obj.GetPosition().y)->isWalkable());
	std::cout << "posx: " << obj.GetPosition().x << std::endl;
	std::cout << "posy: " << obj.GetPosition().y << std::endl;
	std::cout << "dx: " << dx << std::endl;
	std::cout << "dy: " << dy << std::endl;

	result.left = false;
	result.right = false;
	result.floor = false;
	result.ceil = false;
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
		float topY = obj.GetPosition().y + constants::COLLISION_MARGIN;
		float botY = obj.GetPosition().y + obj.GetSize().y - constants::COLLISION_MARGIN;
		Tile* topTile = _map->tileFromPixel(newX, topY);
		Tile* botTile = _map->tileFromPixel(newX, botY);

		if(!topTile->isWalkable() || !botTile->isWalkable()) {
			result.left = left;
			result.right = !left;
			float limit;
			if(left)
				limit = topTile->GetPosition().x + topTile->GetSize().x;
			else
				limit = topTile->GetPosition().x;

			result.dx = limit - forwardX;
		}
		std::cout << "res.dx=" << result.dx << std::endl;

		assert(left  || result.dx <= dx);
		assert(!left || result.dx >= dx);
		//assert(result.dx * dx >= 0); //same direction
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

		Tile* leftTileY = _map->tileFromPixel(objPosX + constants::COLLISION_MARGIN, newY);
		Tile* rightTileY = _map->tileFromPixel(objPosX + obj.GetSize().x - constants::COLLISION_MARGIN, newY);

		if(!leftTileY->isWalkable() || !rightTileY->isWalkable()) {
			result.floor = down;
			result.ceil = !down;
			float limit;
			if(down)
				limit = leftTileY->GetPosition().y;// - constants::COLLISION_MARGIN;
			else
				limit = leftTileY->GetPosition().y + leftTileY->GetSize().y;// + constants::COLLISION_MARGIN;

			result.dy = limit - forwardY;
		}

		std::cout << "res.dy=" << result.dy << std::endl;
		assert(down  || result.dy >= dy);
		assert(!down || result.dy <= dy);
		//assert(result.dy * dy >= 0); //same direction
	}

	return result.floor || result.ceil || result.left || result.right;
}
