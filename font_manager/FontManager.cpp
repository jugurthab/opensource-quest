#include "FontManager.h"

FontManager* FontManager::fontManager = NULL;
FontManager::FontManager(){
    TTF_Init();
}

FontManager::~FontManager(){
    TTF_Quit();
}

SDL_Texture* FontManager::loadFont(std::string FontFilename, std::string fontID, int fontSize){
    SDL_Color color = {255,0,0};
    TTF_Font *font = TTF_OpenFont(FontFilename.c_str(), fontSize);

    if(font==NULL){
        fprintf(stderr, "cannot load font %s", SDL_GetError());
    }

    SDL_Surface *fontSurface = TTF_RenderText_Solid(font, "Welcome to OpenSource Quest", color);
    
    SDL_Texture *fontTexture = SDL_CreateTextureFromSurface(SmileGameLogic::Instance()->getRenderer(), fontSurface);

    TTF_CloseFont(font);


    return fontTexture;    
}
