#ifndef READXML_H
#define READXML_H

#include <vector>
#include "game.h"

std::map<std::string, std::vector<game> > readXMLFile(SDL_Renderer *mainRenderer);

#endif


