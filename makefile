
# The makefile for the project "conjurer+"
# Created by Poul Kalff on the 17. of December, 2015
# This is a test of my prev used command:
#               "g++ -o test conjurer.cpp -lSDL2 -lSDL2_image"


CC = g++
SDL_FLAGS  = -lSDL2 -lSDL2_image -lSDL2_ttf -std=c++0x
TARGET = conjurer+

all: conjurer+

conjurer+: conjurer+.cpp readXML
	$(CC) -o conjurer+ tinyxml2.cpp readXML.cpp tools.cpp textClass.cpp conjurer+.cpp $(SDL_FLAGS)

readXML: readXML.cpp
	$(CC) -c readXML.cpp

tools: tools.cpp
	$(CC) -c tools.cpp

systems: systems.cpp
	$(CC) -c systems.cpp

clean:
	rm conjurer+ *.o

