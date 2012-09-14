#ifndef _HERO_
#define _HERO_

#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "Collision.hpp"

class Hero : public Entity {

public:
	Hero(unsigned int pvMax, float vx, Collision* _collision, sf::RenderWindow* app);

	virtual void act(float elapsedTime);

private:
	sf::RenderWindow* _app;

	Collision* _collision;

	static bool isInstanciated;

};

#endif
