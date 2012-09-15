#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "Hero.hpp"
#include "Map.hpp"
#include "Tile.hpp"
#include "ImageManager.hpp"
#include "Collision.hpp"


int main() {

	std::ifstream mapFile("map.dat");
	Map map;
	map.load(mapFile);


	sf::Clock clock;

  sf::RenderWindow app(sf::VideoMode(640, 480), "SFML Graphics");

	Collision collision(&map);

	Hero hero(100, &collision, &app);


	app.UseVerticalSync(false);
  
  while(app.IsOpened()) {

		float elapsedTime = clock.GetElapsedTime();
		clock.Reset();

		//float framerate = 1.f/elapsedTime;
		//std::cout << "fps: " << framerate << std::endl;

    sf::Event Event;
    while(app.GetEvent(Event)) {
      if(Event.Type == sf::Event::Closed)
        app.Close();
			else if(Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::Space)
				hero.jump();
    }
    
    app.Clear(sf::Color(200, 0, 0));

		hero.act(elapsedTime);

		map.render(app);
		app.Draw(hero);

    app.Display();
  }
  
  return EXIT_SUCCESS;
}
