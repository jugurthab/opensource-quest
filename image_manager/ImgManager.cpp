
#include "ImgManager.h"
ImgManager* ImgManager::imgManager = NULL;
void ImgManager::loadImage(std::string imgFilename, std::string imageID){
    SDL_Surface *tmpImg = NULL;
    SDL_Texture *ImgTexture = NULL;
    tmpImg = SDL_LoadBMP(imgFilename.c_str());

    if(tmpImg==NULL){
        fprintf(stderr, "Cannot Load Image %s\n", SDL_GetError());
        exit(-1);
    }

    ImgTexture = SDL_CreateTextureFromSurface(SmileGameLogic::Instance()->getRenderer(),tmpImg);
    if(ImgTexture==NULL){
        fprintf(stderr, "Cannot Create Texture from Image %s\n", SDL_GetError());
        exit(-1);
    }
    SDL_FreeSurface(tmpImg);


    imgLoaded[imageID] = ImgTexture;

}

void ImgManager::drawImage(std::string imageID, int imgXPos, int imgYPos, int imgWidth, int imgHeight, SDL_RendererFlip flip){
    
    SDL_Rect srcRect, destRect;
    srcRect.x = srcRect.y = 0;

    srcRect.w = destRect.w = imgWidth;
    srcRect.h = destRect.h = imgHeight;

    destRect.x = imgXPos;
    destRect.y = imgYPos;

    SDL_RenderCopyEx(SmileGameLogic::Instance()->getRenderer(), imgLoaded[imageID], &srcRect, &destRect, 0, 0, flip);
}

void ImgManager::drawSpriteAnimation(std::string imageID, int imgXPos, int imgYPos, int imgWidth, int imgHeight, int currentFrame, int currentRow, SDL_RendererFlip flip){
    SDL_Rect srcRect, destRect;
    srcRect.x = currentFrame;

    srcRect.y = currentRow;

    srcRect.w = destRect.w = imgWidth;
    srcRect.h = destRect.h = imgHeight;

    destRect.x = imgXPos;
    destRect.y = imgYPos;

    SDL_RenderCopyEx(SmileGameLogic::Instance()->getRenderer(), imgLoaded[imageID], &srcRect, &destRect, 0, 0, flip);
}