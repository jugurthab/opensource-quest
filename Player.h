#ifndef __Player1__
#define __Player1__
#include <iostream>
#include <SDL.h>
#include "image_manager/ImgManager.h"
 
class Player1 {
    public:
        Player1(){};
        virtual void loadObject(std::string imgFileNameP, std::string imageIDP, int imgXPosP, int imgYPosP, int imgWidthP, int imgHeightP, int currentFrameP, int currentRowP);

        virtual void updateObject();
        
        virtual void drawObject(SDL_RendererFlip flip);  
      private:

        int imgXPos;
        int imgYPos;

        int imgWidth;
        int imgHeight;

        std::string imageID;
        int currentFrame;
        int currentRow;

};


#endif
