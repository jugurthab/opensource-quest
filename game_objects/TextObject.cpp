#include "TextObject.h"

void TextObject::loadObject(std::string imgFileNameP, std::string imageIDP, int imgXPosP, int imgYPosP, int imgWidthP, int imgHeightP, int currentFrameP, int currentRowP){

    imageID = imageIDP;
    currentFrame = currentFrameP;
    currentRow = currentRowP;  
    SDL_Texture *texture = SmileFontManager::Instance()->loadFont(imgFileNameP, imageIDP, fontSizeL, fontColorL, textToBlitP); 
    SDL_QueryTexture(texture, NULL, NULL, &imgWidth, &imgHeight);

    if(imgXPosP==-1)
        imgXPos = (640 - imgWidth)/2;
    else if(imgXPosP==-2)
        imgXPos = 0;
    else if(imgXPosP==-3)
        imgXPos = 640 - imgWidth;
    else
        imgXPos = imgXPosP;

    if(imgYPosP==-1)
        imgYPos = (480 - imgHeight)/2;
    else
        imgYPos = imgYPosP;

    //imgWidth = imgWidthP;
    //imgHeight = imgHeightP;

    
    gameImgManager::Instance()->addTexture(texture, imageID);

}

void TextObject::updateObject(){}

void TextObject::drawObject(SDL_RendererFlip flip){
    if(currentFrame <0 && currentRow<0)
        gameImgManager::Instance()->drawImage(imageID, imgXPos, imgYPos, imgWidth, imgHeight, flip);
    else
        gameImgManager::Instance()->drawSpriteAnimation(imageID, imgXPos, imgYPos,  imgWidth, imgHeight, currentFrame, currentRow, flip);
}

