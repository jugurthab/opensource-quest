#ifndef __USERS__
#define __USERS__
#include "GlobalGameObjectBlueprint.h"
#include "../image_manager/ImgManager.h"
class Users : public GlobalGameObjectBlueprint {
    public:
        Users(){};
        void loadObject(std::string imgFileNameP, std::string imageIDP, int imgXPosP, int imgYPosP, int imgWidthP, int imgHeightP, int currentFrameP, int currentRowP);

        void updateObject();
        
        void drawObject(SDL_RendererFlip flip);  
    

};


#endif
