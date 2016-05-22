#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "textClass.h"

// Hvad er det, at denne klasse skal?
// ----------------------------------------------
//   - Modtage fra parent HVAD DER SKAL LAVES
//   - Rendere den text der skal vaere paa skaermen
//   - Rendere den (eller returnere til parent... probably not?)




TTF_Font *fontSystem, *fontSystemFocus, *fontGame, *fontGameFocus;
SDL_Color colWhite;
SDL_Texture *tSysL, *tSysC, *tSysR;
SDL_Rect solidRect2;
SDL_Renderer *mainRenderer;

TextClass::TextClass(SDL_Renderer *mainRendererInd)
{
    TTF_Init();
    mainRenderer = mainRendererInd;
    fontSystem = TTF_OpenFont("fonts/LiberationMono-Regular.ttf", 34);
    fontSystemFocus = TTF_OpenFont("fonts/LiberationMono-Bold.ttf", 34);
    fontGame = TTF_OpenFont("fonts/LiberationMono-Regular.ttf", 40);
    fontGameFocus = TTF_OpenFont("fonts/LiberationMono-Bold.ttf", 40);
    colWhite = {255, 255, 255, 155};
};

// Paints (i.e. as gfx) the Systems on screen
void  TextClass::paintSystems(std::vector<std::string> liste)
{
    std::cout << "1. " << liste[0] << std::endl;
    std::cout << "2. " << liste[1] << std::endl;
    std::cout << "3. " << liste[2] << std::endl;
				    // Foelgende 3 hoerer sammen og boer vaere liste/vector, paa sigt
    tSysL = _SurfaceToTexture( TTF_RenderText_Solid( fontSystem, liste[0].c_str(), colWhite ) );
    tSysC = _SurfaceToTexture( TTF_RenderText_Solid( fontSystemFocus, liste[1].c_str(), colWhite ) );
    tSysR = _SurfaceToTexture( TTF_RenderText_Solid( fontSystem, liste[2].c_str(), colWhite ) );




//      	NEXT STEP: How was this in working example?

//    SDL_QueryTexture( textureSystemFocus, NULL, NULL, &solidRect.w, &solidRect.h );
//    solidRect.x = 200;
//    solidRect.y = 100;
//    SDL_RenderCopy( gRenderer, textureSystemFocus, NULL, &solidRect );

}






// INTERNAL: Converts an SDL_Surface to SDL_Texture
SDL_Texture* TextClass::_SurfaceToTexture(SDL_Surface* surface)
{
        SDL_Texture* texture = SDL_CreateTextureFromSurface(mainRenderer, surface);
        SDL_FreeSurface(surface);
        return texture;
}

//void TextClass::updateText()	// Model function, never to be used
//{
//    textureSystemFocus = _SurfaceToTexture( TTF_RenderText_Solid( fontSystemFocus, "AMIGA", colWhite ) );
//    SDL_QueryTexture( textureSystemFocus, NULL, NULL, &solidRect.w, &solidRect.h );
//    solidRect.x = 200;
//    solidRect.y = 100;
//}






