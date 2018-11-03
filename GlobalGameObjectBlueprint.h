#ifndef __GlobalGameObjectBlueprint__
#define __GlobalGameObjectBlueprint__
#include <iostream>
#include <SDL.h>
#include "image_manager/ImgManager.h"
class GlobalGameObjectBlueprint {
    public:
        virtual void loadObject(std::string imgFileNameP, std::string imageIDP, int imgXPosP, int imgYPosP, int imgWidthP, int imgHeightP, int currentFrameP, int currentRowP);

        virtual void updateObject();
        
        virtual void drawObject(SDL_RendererFlip flip);
    
    protected:

        int imgXPos;
        int imgYPos;

        int imgWidth;
        int imgHeight;

        std::string imageID;
        int currentFrame;
        int currentRow;
};


#endif 
