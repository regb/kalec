#include <iostream>
#include <SFML/Graphics.hpp>

#include "Globals.hpp"
#include "WalkableTile.hpp"

WalkableTile::WalkableTile() {
	SetImage(imageManager.getGrass());
}
