#include <sstream>	// for ostringstream
#include <typeinfo>	// for typeid
#include <iostream>	// for cout
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <vector>
#include <map>
#include "tinyxml2.h"
#include "game.h"
#include "textClass.h"
#include "readXML.h"
#include "tools.h"
using namespace std;

SDL_Window *gWindow;
SDL_Renderer *gRenderer;
game activeGame;
StringIterator objStringItr({"Amiga", "Arcade", "C64"}, true);
vector<RangeIterator> systemsArray;
bool running = true;
bool initSDL();
bool checkKeys();
bool drawScreen();
bool cleanUp();


int main( int argc, char* args[] )
{
    initSDL();
    map<string, vector<game> > gamesList = readXMLFile(gRenderer);
    systemsArray.push_back(RangeIterator(gamesList["Amiga"].size() - 1, false));
    systemsArray.push_back(RangeIterator(gamesList["Arcade"].size() - 1, false));
    systemsArray.push_back(RangeIterator(gamesList["C64"].size() - 1, false));
    TextClass textWriter(gRenderer);
    textWriter.paintSystems(objStringItr.getList());

    while(running)
    {
        checkKeys();
        activeGame = gamesList[objStringItr.getCentral()][systemsArray[objStringItr.getCentralNo()].get()];
      //  updateText();
        drawScreen();
    }

    cleanUp();
    return 1;
}


bool initSDL()
{
    // Initialize SDL
    SDL_Init( SDL_INIT_VIDEO );
    gWindow = SDL_CreateWindow( "Conjurer+", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN );
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    return 1;
}


bool checkKeys()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        // check for messages
        switch (event.type)
        {
            // exit if the window is closed
            case SDL_QUIT:
                running = false;
                break;
            // check for keypresses
            case SDL_KEYDOWN:
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                        systemsArray[objStringItr.getCentralNo()].dec(1);
                        break;
                    case SDLK_DOWN:
                        systemsArray[objStringItr.getCentralNo()].inc(1);
                        break;
                    case SDLK_LEFT:
                        objStringItr.inc(1);
                        break;
                    case SDLK_RIGHT:
                        objStringItr.dec(1);
                        break;
                    case SDLK_ESCAPE:
                        running = false;
                        break;
                }
            }
        } // end switch
    }
    return 1;
}

bool drawScreen()
{
    // Render Screen
    SDL_RenderCopy(gRenderer, activeGame.screenShot, NULL, NULL);


    // Render text
//    SDL_RenderCopy( gRenderer, textureSystemFocus, NULL, &solidRect );


    SDL_RenderPresent(gRenderer);
    return 1;
}

bool cleanUp()
{
    // Clean up everything
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
//    TTF_CloseFont(fontSystem);
//    TTF_CloseFont(fontSystemFocus);
//    TTF_CloseFont(fontGame);
//    TTF_CloseFont(fontGameFocus);
//    TTF_Quit();
    SDL_Quit();
    return 1;
}

