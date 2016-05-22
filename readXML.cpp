#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "tinyxml2.h"
#include "readXML.h"
#include "game.h"

// Returns a list of objects, created from xml-file
std::map<std::string, std::vector<game> > readXMLFile(SDL_Renderer *mainRenderer)
{
    tinyxml2::XMLDocument doc;
    doc.LoadFile( "xml/games.xml" );
    tinyxml2::XMLElement* collectionElement = doc.FirstChildElement( "collection" );
    tinyxml2::XMLElement* gameElement = collectionElement->FirstChildElement( "game" );
    std::map< std::string, std::vector<game> > gamesList;
    std::string tmpStr;

    while (gameElement != NULL)
    {
        game objGame;
        objGame.name = gameElement->FirstChildElement("name")->GetText();
        objGame.system = gameElement->FirstChildElement("system")->GetText();
        objGame.maxPlayers = atoi(gameElement->FirstChildElement("players")->GetText());
        tmpStr = gameElement->FirstChildElement("rompath")->GetText();
        for(size_t p=0, q=0; p != tmpStr.npos; p=q)	// slicing paths and adding to vector
        {
            std::string path = tmpStr.substr(p+(p!=0), (q=tmpStr.find(";", p+1))-p-(p!=0));
            size_t endpos = path.find_last_not_of(" \t");	// removing start/ending whitespace
            size_t startpos = path.find_first_not_of(" \t");
            if( std::string::npos != endpos )
                path = path.substr( 0, endpos+1 );
            if( std::string::npos != startpos )
                path = path.substr( startpos );
            objGame.romPath.push_back(path);
        }
        std::string screenPath = gameElement->FirstChildElement("screenpath")->GetText();
        SDL_Surface *surf = IMG_Load(screenPath.c_str());
        objGame.screenShot = SDL_CreateTextureFromSurface(mainRenderer, surf);
        SDL_FreeSurface(surf);
        if (objGame.system == "Amiga")
            gamesList["Amiga"].push_back(objGame);
        else if (objGame.system == "Arcade")
            gamesList["Arcade"].push_back(objGame);
        else if (objGame.system == "C64")
            gamesList["C64"].push_back(objGame);
	gameElement = gameElement->NextSiblingElement("game");
    }
    return gamesList;
}
