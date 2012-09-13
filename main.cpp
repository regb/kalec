#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "Globals.hpp"

#include "Entity.hpp"
#include "Hero.hpp"
#include "Map.hpp"
#include "Tile.hpp"

ImageManager imageManager;
Hero hero(100);
Map map;

int main() {

	std::ifstream mapFile("map.dat");
	Map map;
	map.load(mapFile);

  sf::RenderWindow App(sf::VideoMode(640, 480), "SFML Graphics");

  
  while(App.IsOpened()) {
    sf::Event Event;
    while(App.GetEvent(Event)) {
      if(Event.Type == sf::Event::Closed)
        App.Close();
    }
    
    App.Clear(sf::Color(200, 0, 0));


		map.render(App);

    App.Display();
  }
  
  return EXIT_SUCCESS;
}
