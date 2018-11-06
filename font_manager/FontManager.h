
#ifndef __FontManager__
#define __FontManager__
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "../GameLogic.h"
class FontManager{
    public:

        static FontManager* Instance(){
            if(fontManager == NULL)
                fontManager = new FontManager();
            return fontManager;
        } 
        SDL_Texture* loadFont(std::string FontFilename, std::string fontID, int fontSize, SDL_Color color);


    private:
        FontManager();
        ~FontManager();
        static FontManager* fontManager;
};

typedef FontManager SmileFontManager;

#endif
