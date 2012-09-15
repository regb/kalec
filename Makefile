UNAME = $(shell uname)

ifeq (${UNAME}, Linux)
LCFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
else
LCFLAGS=-framework sfml-graphics -framework sfml-window -framework sfml-system
endif


kalec: main.cpp Wall.o WalkableTile.o Map.o Hero.o ImageManager.o Tile.o Entity.o Collision.o
	g++ -Wall -o kalec main.cpp ImageManager.o Wall.o WalkableTile.o Map.o Hero.o Tile.o Entity.o Collision.o ${LCFLAGS}

Hero.hpp: Entity.hpp Collision.hpp
Map.hpp: Tile.hpp Entity.hpp ImageManager.hpp Wall.hpp WalkableTile.hpp
WalkableTile.hpp: Tile.hpp
Wall.hpp: Tile.hpp
Tile.hpp: ImageManager.hpp
main.hpp: Entity.hpp Hero.hpp Map.hpp Tile.hpp ImageManager.hpp
Collision.hpp: Map.hpp Tile.hpp Constants.hpp

Wall.o: Wall.cpp Wall.hpp
	g++ -Wall -c Wall.cpp

WalkableTile.o: WalkableTile.cpp WalkableTile.hpp
	g++ -Wall -c WalkableTile.cpp

Map.o: Map.cpp Map.hpp 
	g++ -Wall -c Map.cpp

Hero.o: Hero.cpp Hero.hpp constants.hpp
	g++ -Wall -c Hero.cpp

Tile.o: Tile.cpp Tile.hpp
	g++ -Wall -c Tile.cpp

ImageManager.o: ImageManager.cpp ImageManager.hpp
	g++ -Wall -c ImageManager.cpp

Collision.o: Collision.cpp Collision.hpp
	g++ -Wall -c Collision.cpp

Entity.o: Entity.cpp Entity.hpp
	g++ -Wall -c Entity.cpp

clean:
	rm *.o
