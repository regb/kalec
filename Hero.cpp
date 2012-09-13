#include "Hero.hpp"

void Hero::act() {

}

Hero::Hero(unsigned int pvMax) : Entity(pvMax) {
	sf::Image image;
	image.LoadFromFile("hero.png");
	SetImage(image);
}
