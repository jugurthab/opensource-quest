#include "GlobalGameObjectBlueprint.h"
 #include "../image_manager/ImgManager.h"
#ifndef __PlayUser__
#define __PlayUser__

class PlayerUser : public GlobalGameObjectBlueprint {
    public:
        PlayerUser(){};
        void loadObject(std::string imgFileNameP, std::string imageIDP, int imgXPosP, int imgYPosP, int imgWidthP, int imgHeightP, int currentFrameP, int currentRowP);

        void updateObject();
        
        void drawObject(SDL_RendererFlip flip);  
    

};


#endif
