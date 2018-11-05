#include "TextObject.h"

void TextObject::loadObject(std::string imgFileNameP, std::string imageIDP, int imgXPosP, int imgYPosP, int imgWidthP, int imgHeightP, int currentFrameP, int currentRowP){

    imageID = imageIDP;
    currentFrame = currentFrameP;
    currentRow = currentRowP;  
    SDL_Texture *texture = SmileFontManager::Instance()->loadFont(imgFileNameP, imageIDP, 30); 
    SDL_QueryTexture(texture, NULL, NULL, &imgWidth, &imgHeight);

    imgXPos = (640 - imgWidth)/2;
    
    //imgWidth = imgWidthP;
    imgHeight = imgHeightP;

    
    gameImgManager::Instance()->addTexture(texture, imageID);

}

void TextObject::updateObject(){}

void TextObject::drawObject(SDL_RendererFlip flip){
    if(currentFrame <0 && currentRow<0)
        gameImgManager::Instance()->drawImage(imageID, imgXPos, imgYPos, imgWidth, imgHeight, flip);
    else
        gameImgManager::Instance()->drawSpriteAnimation(imageID, imgXPos, imgYPos,  imgWidth, imgHeight, currentFrame, currentRow, flip);
}

