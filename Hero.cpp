#include "Hero.hpp"
#include <iostream>

#include <SFML/Graphics.hpp>
#include "ImageManager.hpp"
#include "constants.hpp"

bool Hero::isInstanciated = false;

void Hero::act(float elapsedTime) {
	const sf::Input& input = _app->GetInput();

	//jump
	if(input.IsKeyDown(sf::Key::Up)) {
		if(_vy == 0.f)
			_vy = -200.f;
	}

	//apply forces
	_vy = _vy + constants::GRAVITY*elapsedTime;

	if(input.IsKeyDown(sf::Key::Left))
		_vx = _vx + -100.f*elapsedTime;
	if(input.IsKeyDown(sf::Key::Right))
		_vx = _vx + 100.f*elapsedTime;

	float friction = 60.f*elapsedTime;
	if(_vx < friction && _vx > -friction)
		_vx = 0.f;
	if(_vx > 0)
		_vx = _vx - friction;
	else
		_vx = _vx + friction;


	float dx = _vx*elapsedTime;
	float dy = _vy*elapsedTime;

	CollisionResult colRes;
	if(!_collision->collide(*this, dx, dy, colRes)) {
		Move(dx, dy);
	} else {
		std::cout << "collision!, dx=" << colRes.dx << ", dy=" << colRes.dy << std::endl;
		Move(colRes.dx, colRes.dy);
		if(colRes.floor)
			_vy = 0.f;
		if(colRes.side)
			_vx = 0.f;
	}

}

Hero::Hero(unsigned int pvMax, Collision* collision, sf::RenderWindow* app) : Entity(pvMax), _app(app), _collision(collision) {
	if(isInstanciated)
		exit(-1);
	isInstanciated = true;
	SetImage(ImageManager::getImage(ImageManager::loadImage("hero.png")));
}
