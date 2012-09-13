#ifndef _IMAGEMANAGER_
#define _IMAGEMANAGER_

#include <SFML/Graphics.hpp>

class ImageManager {

public:

	ImageManager();

	inline sf::Image& getWall() {
		return _wall;
	}
	inline sf::Image& getGrass() {
		return _grass;
	}


private:

	sf::Image _wall;
	sf::Image _grass;

};

#endif
