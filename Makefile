UNAME = $(shell uname)

ifeq (${UNAME}, Linux)
LCFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
else
LCFLAGS=-framework sfml-graphics -framework sfml-window -framework sfml-system
endif


kalec: Wall.o WalkableTile.o Map.o Hero.o ImageManager.o
	g++ -o kalec main.cpp Wall.o WalkableTile.o Map.o Hero.o ImageManager.o ${LCFLAGS}


Wall.o: Wall.cpp Wall.hpp Tile.hpp
	g++ -Wall -c Wall.cpp

WalkableTile.o: WalkableTile.cpp WalkableTile.hpp Tile.hpp
	g++ -Wall -c WalkableTile.cpp

Map.o: Map.cpp Map.hpp Tile.hpp Entity.hpp
	g++ -Wall -c Map.cpp

Hero.o: Hero.cpp Hero.hpp Entity.hpp
	g++ -Wall -c Hero.cpp

ImageManager.o: ImageManager.cpp ImageManager.hpp
	g++ -Wall -c ImageManager.cpp
