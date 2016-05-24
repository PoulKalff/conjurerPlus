#ifndef DRAWTEXT_H
#define DRAWTEXT_H

#include <SDL2/SDL.h>

class TextClass
{
  public:
    TextClass(SDL_Renderer *mainRendererInd);
    void paintSystems(std::vector<std::string> listeIn);
    SDL_Texture* _SurfaceToTexture(SDL_Surface* surface);
};


#endif


