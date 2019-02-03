
#ifndef __ENEMY__
#define __ENEMY__
#include "GlobalGameObjectBlueprint.h"
 #include "../image_manager/ImgManager.h"
class Enemy : public GlobalGameObjectBlueprint {
    public:
        Enemy(){};
        void loadObject(std::string imgFileNameP, std::string imageIDP, int imgXPosP, int imgYPosP, int imgWidthP, int imgHeightP, int currentFrameP, int currentRowP);

        void updateObject();
        
        void drawObject(SDL_RendererFlip flip);
        void generateDisplacePosition();        

        void setdX(int dxUser){dx = dxUser;}
        int getdX(){return dx;}
        void setdY(int dyUser){dy = dyUser;}
        int getdY(){return dy;}
    private:
        int dx, dy; 
        
};


#endif
