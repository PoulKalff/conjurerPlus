#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>

class game
{
  public:
    std::string name;
    std::string system;
    int maxPlayers;
    std::vector<std::string> romPath;
    SDL_Texture *screenShot;
};

#endif

