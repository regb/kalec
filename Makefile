UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
else ifeq ($(UNAME), Darwin)
LDFLAGS=-framework sfml-graphics -framework sfml-window -framework sfml-system
endif

CFLAGS= -Wall

SOURCES = $(shell find . -name "*.cpp")
HEADERS = $(shell find . -name "*.hpp")
OBJS = $(patsubst %.cpp,%.o,$(SOURCES))

CC = g++

.DEFAULT_GOAL = kalec

#Just in case .DEFAULT_GOAL is not supported
all: kalec

depend:
	$(CC) $(CFLAGS) -MM $(SOURCES) $(HEADERS) > Makefile.deps

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

#MAIN build rule
kalec: $(OBJS)
	$(CC) -o kalec $(CFLAGS) $^ $(LDFLAGS)
.PHONY: clean
clean:
	for obj in kalec $(OBJS); do if [ -f $$obj ]; then  rm $$obj; fi; done

-include Makefile.deps
