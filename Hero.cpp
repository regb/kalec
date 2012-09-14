#include "Hero.hpp"
#include <iostream>

#include <SFML/Graphics.hpp>
#include "ImageManager.hpp"

bool Hero::isInstanciated = false;

void Hero::act(float elapsedTime) {
	float dx=0, dy=0;
	const sf::Input& input = _app->GetInput();
	if(input.IsKeyDown(sf::Key::Left))
		dx = -_vx * elapsedTime;
	if(input.IsKeyDown(sf::Key::Right))
		dx = _vx * elapsedTime;
	if(input.IsKeyDown(sf::Key::Up))
		dy = -50 * elapsedTime;
	if(input.IsKeyDown(sf::Key::Down))
		dy = 50 * elapsedTime;

	dy += _vy*elapsedTime;

	bool floor;
	if(!_collision->collide(*this, dx, dy, floor))
		Move(dx, dy);

  if(air()) {
    if(floor)
      land();
    else
      _vy += 50*elapsedTime;
  }

}

Hero::Hero(unsigned int pvMax, float vx, Collision* collision, sf::RenderWindow* app) : Entity(pvMax, vx), _app(app), _collision(collision) {
	if(isInstanciated)
		exit(-1);
	isInstanciated = true;
	SetImage(ImageManager::getImage(ImageManager::loadImage("hero.png")));
}
