#ifndef _IMAGEMANAGER_
#define _IMAGEMANAGER_

#include <iostream>
#include <SFML/Graphics.hpp>

class ImageManager {

public:

	static sf::Image& getImage(unsigned id); 

	static unsigned loadImage(const std::string& filename);

private:

	static std::vector<sf::Image> images;

};

#endif
