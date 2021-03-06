#include "PlayerUser.h"

void PlayerUser::loadObject(std::string imgFileNameP, std::string imageIDP, int imgXPosP, int imgYPosP, int imgWidthP, int imgHeightP, int currentFrameP, int currentRowP){
    imgXPos = imgXPosP;
    imgYPos = imgYPosP;

    imgWidth = imgWidthP;
    imgHeight = imgHeightP;

    imageID = imageIDP;
    currentFrame = currentFrameP;
    currentRow = currentRowP;    
    gameImgManager::Instance()->loadImage(imgFileNameP, imageID);

}

void PlayerUser::updateObject(){
}

void PlayerUser::drawObject(SDL_RendererFlip flipUser){
    if(currentFrame <0 && currentRow<0)
        gameImgManager::Instance()->drawImage(imageID, imgXPos, imgYPos, imgWidth, imgHeight, flip);
    else
        gameImgManager::Instance()->drawSpriteAnimation(imageID, imgXPos, imgYPos,  imgWidth, imgHeight, currentFrame, currentRow, flip);
}

