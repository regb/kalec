#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "Hero.hpp"
#include "Map.hpp"
#include "Tile.hpp"
#include "ImageManager.hpp"
#include "Collision.hpp"
#include "constants.hpp"


int main() {

	std::ifstream mapFile("map.dat");
	Map map;
	map.load(mapFile);


	sf::Clock clock;

  sf::RenderWindow app(sf::VideoMode(
		constants::WINDOW_WIDTH*constants::TILE_WIDTH, constants::WINDOW_HEIGHT*constants::TILE_HEIGHT),
		"SFML Graphics");

	Collision collision(&map);

	Hero hero(100, &collision, &app);


	app.UseVerticalSync(false);

	sf::View view(map.window());
	app.SetView(view);
  
  while(app.IsOpened()) {

		float elapsedTime = clock.GetElapsedTime();
		clock.Reset();

		//float framerate = 1.f/elapsedTime;
		//std::cout << "fps: " << framerate << std::endl;

    sf::Event Event;
    while(app.GetEvent(Event)) {
      if(Event.Type == sf::Event::Closed)
        app.Close();
			//else if(Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::Space)
			//	hero.jump();
    }
    
    app.Clear(sf::Color(200, 0, 0));

		hero.act(elapsedTime);

		map.render(app);

		map.setWidowCenter(hero.GetPosition().x + hero.GetSize().x/2, hero.GetPosition().y + hero.GetSize().y/2);
		app.SetView(sf::View(map.window()));

		app.Draw(hero);

    app.Display();
  }
  
  return EXIT_SUCCESS;
}
