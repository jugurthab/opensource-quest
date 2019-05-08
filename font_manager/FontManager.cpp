#include "FontManager.h"

FontManager* FontManager::fontManager = NULL;
FontManager::FontManager(){
    TTF_Init();
}

FontManager::~FontManager(){
    TTF_Quit();
}

SDL_Texture* FontManager::loadFont(std::string FontFilename, std::string fontID, int fontSize, SDL_Color color, std::string textToBlit){
    TTF_Font *font = TTF_OpenFont(FontFilename.c_str(), fontSize);

    if(font==NULL){
        fprintf(stderr, "cannot load font %s", SDL_GetError());
    }

    SDL_Surface *fontSurface = TTF_RenderText_Blended(font, textToBlit.c_str(), color);
    
    SDL_Texture *fontTexture = SDL_CreateTextureFromSurface(SmileGameLogic::Instance()->getRenderer(), fontSurface);
    
    SDL_FreeSurface(fontSurface);
    TTF_CloseFont(font);

    return fontTexture;    
}
