#include "GameScene.h"
#include <cstdlib>
#include <ctime>

const std::string GameScene::gameStateID = "GAME_STATE";

char* GameScene::setTimeLeftText(){
    char* tmp;
    sprintf(tmp, "Time left : %d", timeLeft);
    return tmp;
}

void GameScene::updateState(){
    timeEllapsedTimer = SDL_GetTicks();
    // Reduce timeleft by 1 second.
    if(timeEllapsedTimer - timeStartGameTimer > 1000){
        gameImgManager::Instance()->eraseImg("gameScene");
        timeLeft-=1;
        GameSceneText = new TextObject(20, {255,0,0}, setTimeLeftText());
        GameSceneText->loadObject("assets/fonts/Deutsch.ttf", "gameScene", 20, 30, 400, 60, -1, -1);
        stateObjects.push_back(GameSceneText);
        timeStartGameTimer = timeEllapsedTimer;
        GameSceneText->updateObject();
    }
    
    timeEllapsedToUpdate = SDL_GetTicks();
    if(timeEllapsedToUpdate - timeStart > 100){
        if(playerUserCurrentFrame==2)
                playerUserCurrentFrame=-1;
        playerUserCurrentFrame += 1;
        pUser->setCurrentFrame(playerUserCurrentFrame);
        timeStart = timeEllapsedToUpdate;

        if(dx!=0){
            if(dx==50 || dx==-50){
                dx=0;
                playerUserCurrentRow = 0;
            }
            else{
                dx += delta;
                playerUserCurrentRow = 7;
            }
            pUser->setImgXPos(pUser->getImgXPos()+delta);    
        }

        if(dy!=0){
            if(dy==50 || dy==-50){
                dy=0;
                playerUserCurrentRow = 0;
            }
            else{
                dy += delta;
                if (dy<0)
                    playerUserCurrentRow = 2;
                else
                    playerUserCurrentRow = 1;
            }
            pUser->setImgYPos(pUser->getImgYPos()+delta);
        }

            for(int i=0; i<stateObjects.size();i++){
             stateObjects[i]->updateObject();  
             if(stateObjects[i]->getObjectType() == std::string("enemies")){
                if((pUser->getImgYPos()) == stateObjects[i]->getImgYPos() && pUser->getImgXPos() == stateObjects[i]->getImgXPos()){
                        playerUserCurrentRow = 8;
                }

                if(stateObjects[i]->getImgXPos()%50 ==0){
                    static_cast<Enemy*>(stateObjects[i])->setdX(0);
                }
                if(stateObjects[i]->getImgYPos()%50 ==0){
                    static_cast<Enemy*>(stateObjects[i])->setdY(0);
                }
                if(static_cast<Enemy*>(stateObjects[i])->getdX()==0 && static_cast<Enemy*>(stateObjects[i])->getdY()==0){
                    directionChooser = rand() % 100;
                    //std::cout << directionChooser << std::endl;
                    if(directionChooser<50){
                        directionChooser = rand() % 100;
                        if(directionChooser < 50)
                            static_cast<Enemy*>(stateObjects[i])->setdX(10);
                        else
                            static_cast<Enemy*>(stateObjects[i])->setdX(-10);

                    } else{
                        directionChooser = rand() % 100;
                        if(directionChooser < 50)
                            static_cast<Enemy*>(stateObjects[i])->setdY(10);
                        else
                            static_cast<Enemy*>(stateObjects[i])->setdY(-10);
                    }
                }

                if(stateObjects[i]->getImgXPos()+ static_cast<Enemy*>(stateObjects[i])->getdX() < 640 && stateObjects[i]->getImgXPos() + static_cast<Enemy*>(stateObjects[i])->getdX()>0 && static_cast<Enemy*>(stateObjects[i])->getdX()!=0){ 
                for(int n=0; n<stateObjects.size();n++){
                             if(stateObjects[n]->getObjectType() ==std::string("obstacles")){
                                    if( ( (static_cast<Enemy*>(stateObjects[i])->getdX()>=0 && (stateObjects[i]->getImgXPos()+50 == stateObjects[n]->getImgXPos()) ) || (static_cast<Enemy*>(stateObjects[i])->getdX()<0 && (stateObjects[i]->getImgXPos()-50 == stateObjects[n]->getImgXPos())) )
                                    && (stateObjects[i]->getImgYPos() == stateObjects[n]->getImgYPos())
                                    ){
                                                static_cast<Enemy*>(stateObjects[i])->setdX(0);
                                        break;
                                    }                            

                             }
           
                }
                        stateObjects[i]->setImgXPos(stateObjects[i]->getImgXPos()+ static_cast<Enemy*>(stateObjects[i])->getdX());  
                }else if(stateObjects[i]->getImgXPos() < 50){
                    static_cast<Enemy*>(stateObjects[i])->setdX(10);
                }else if(stateObjects[i]->getImgXPos() >=600){
                    static_cast<Enemy*>(stateObjects[i])->setdX(-10);
                }

                
                else if(stateObjects[i]->getImgYPos()+static_cast<Enemy*>(stateObjects[i])->getdY() < 480 && stateObjects[i]->getImgYPos() + static_cast<Enemy*>(stateObjects[i])->getdY()>0 && static_cast<Enemy*>(stateObjects[i])->getdY()!=0){
                for(int n=0; n<stateObjects.size();n++){
                             if(stateObjects[n]->getObjectType() ==std::string("obstacles")){
                                    if( ( (static_cast<Enemy*>(stateObjects[i])->getdY()>=0 && (stateObjects[i]->getImgYPos()+50 == stateObjects[n]->getImgYPos()) ) || (static_cast<Enemy*>(stateObjects[i])->getdY()<0 && (stateObjects[i]->getImgYPos()-50 == stateObjects[n]->getImgYPos())) )
                                    && (stateObjects[i]->getImgXPos() == stateObjects[n]->getImgXPos())
                                    ){
                                                static_cast<Enemy*>(stateObjects[i])->setdY(0);
                                        break;
                                    }                            

                             }
           
                }
                        stateObjects[i]->setImgYPos(stateObjects[i]->getImgYPos()+ static_cast<Enemy*>(stateObjects[i])->getdY());  
                }else if(stateObjects[i]->getImgYPos() < 50){
                     static_cast<Enemy*>(stateObjects[i])->setdY(10);
                }else if(stateObjects[i]->getImgYPos() >=440){
                     static_cast<Enemy*>(stateObjects[i])->setdY(-10);
                }

                for(int j=0; j<stateObjects.size();j++){
                    if(stateObjects[j]->getObjectType() == std::string("boy") || stateObjects[j]->getObjectType() == std::string("girl") || stateObjects[j]->getObjectType() == std::string("boyGreen")){
                        if(stateObjects[i]->getImgXPos() == stateObjects[j]->getImgXPos() && stateObjects[i]->getImgYPos() == stateObjects[j]->getImgYPos()){
                            stateObjects[j]->setCurrentRow(4);
                            stateObjects[j]->setCurrentFrame(playerUserCurrentFrame);
                        }
                        
                    }

                }    
                
            }

            else if(stateObjects[i]->getObjectType() == std::string("boy")){
                if((pUser->getImgYPos()) == stateObjects[i]->getImgYPos() && pUser->getImgXPos() == stateObjects[i]->getImgXPos()){
                    stateObjects[i]->setCurrentRow(0);
                    
                }
                stateObjects[i]->setCurrentFrame(playerUserCurrentFrame);
            }
            else if(stateObjects[i]->getObjectType() == std::string("girl")){
                if((pUser->getImgYPos()) == stateObjects[i]->getImgYPos() && pUser->getImgXPos() == stateObjects[i]->getImgXPos()){
                    stateObjects[i]->setCurrentRow(0);
                    
                }
                stateObjects[i]->setCurrentFrame(3+playerUserCurrentFrame);
            }
            else if(stateObjects[i]->getObjectType() == std::string("boyGreen")){
                if((pUser->getImgYPos()) == stateObjects[i]->getImgYPos() && pUser->getImgXPos() == stateObjects[i]->getImgXPos()){
                    stateObjects[i]->setCurrentRow(0);

                }
                    stateObjects[i]->setCurrentFrame(6+playerUserCurrentFrame);
            }
        }     

    }
    pUser->setCurrentRow(playerUserCurrentRow);

}

void GameScene::renderState(){    
    for (std::vector<GlobalGameObjectBlueprint*>::iterator it = stateObjects.begin() ; it != stateObjects.end(); ++it)
    {
            (*it)->drawObject(SDL_FLIP_NONE);

    }
    GameSceneText->drawObject(SDL_FLIP_NONE);
}
        
bool GameScene::parseXMLLevel(){
   // create main level XML document container
    tinyxml2::XMLDocument xmlDoc;
        
    // load xml file
    if(xmlDoc.LoadFile("game_levels/level1.xml") != tinyxml2::XML_SUCCESS)
    {
        std::cerr << "loading XML level file failed " << xmlDoc.ErrorID() <<"\n";
        return false;
    }

    tinyxml2::XMLNode* pRoot = xmlDoc.RootElement();
    // Check if pRoot is non empty
    if (pRoot == NULL){
        std::cout << "Invalid XML file" << std::endl;
        return false;
    }   

    for(tinyxml2::XMLElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {      
        if(e->Value() == std::string("level_difficulty")){
            std::cout << "level_difficulty : " << e->GetText() << std::endl;
        }
        else if(e->Value() == std::string("player")){ 
            int posX = 0, posY = 0;
            std::string pathToImg = "assets/";
            pathToImg += e->Attribute("id");
            for(tinyxml2::XMLElement* subEl = e->FirstChildElement(); subEl != NULL; subEl = subEl->NextSiblingElement()){
                
                if(subEl->Value() == std::string("positionX"))
                    posX = atoi(subEl->GetText());
                else
                    posY = atoi(subEl->GetText());
            }
            pUser->loadObject(pathToImg, "linux", posX, posY, 50, 50, 0, 7);
            stateObjects.push_back(pUser);
        }

        else if(e->Value() == std::string("enemies")) {
            int posX = 0, posY = 0;
            std::string pathToImg = "assets/";
            pathToImg += e->Attribute("id");
            for(tinyxml2::XMLElement* subEl = e->FirstChildElement(); subEl != NULL; subEl = subEl->NextSiblingElement()){
                Enemy* enemy = new Enemy();
                
                posX = atoi(subEl->Attribute("x"));
                posY = atoi(subEl->Attribute("y"));
                enemy->loadObject(pathToImg, e->Attribute("id"), posX, posY, 50, 50, 0, 0);
                enemy->setObjectType("enemies");
                stateObjects.push_back(enemy); 
            }         
  
        }
    
        else if(e->Value() == std::string("obstacles")){
            int posX = 0, posY = 0;
            std::string pathToImg = "assets/";
            pathToImg += e->Attribute("id");
            for(tinyxml2::XMLElement* subEl = e->FirstChildElement(); subEl != NULL; subEl = subEl->NextSiblingElement()){
                Block* block = new Block();
                posX = atoi(subEl->Attribute("x"));
                posY = atoi(subEl->Attribute("y"));

                block->loadObject(pathToImg, "block", posX, posY, 50, 50, 0, 0);
                block->setObjectType("obstacles");
                stateObjects.push_back(block);
            }  
        }

        else if(e->Value() == std::string("users")){
            int posX = 0, posY = 0;
            std::string pathToImg = "assets/";
            pathToImg += e->Attribute("id");
            std::cout << e->Attribute("id") << std::endl;
            for(tinyxml2::XMLElement* subEl = e->FirstChildElement(); subEl != NULL; subEl = subEl->NextSiblingElement()){
                Users* user = new Users();
                posX = atoi(subEl->Attribute("x"));
                posY = atoi(subEl->Attribute("y"));
                user->loadObject(pathToImg, "users", posX, posY, 50, 50, atoi(subEl->Attribute("currentFrame")), atoi(subEl->Attribute("currentRow")));
                user->setObjectType(subEl->Attribute("type"));
                stateObjects.push_back(user);
            }  
        }
        else if(e->Value() == std::string("play_time")){
            timeLeft = atoi(e->GetText());
        } 
    } 
}


void GameScene::handleEvent(){
    SDL_Event event = smileHandleUserEvent::Instance()->updateUserInput();

    switch(event.type){
        
        case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        std::cout << "GameScene" <<std::endl;
                        SmileStateMachine::Instance()->switchState(new GameOverScene());
                    break;
                    
                    case SDLK_UP:
                        if((pUser->getImgYPos()-50) >= 0 && dy==0 && dx==0){
                            for(int i=0; i<stateObjects.size();i++){
                                if(stateObjects[i]->getObjectType() ==std::string("obstacles")){
                                    if((pUser->getImgYPos()-50) == stateObjects[i]->getImgYPos() && pUser->getImgXPos() == stateObjects[i]->getImgXPos())
                                        return;
                                }
                            }
                            delta = -10; dy= -10;
                        }
                        playerUserCurrentRow = 2;
                    break;
            
                    case SDLK_DOWN:
                        if((pUser->getImgYPos()+50) <= 480 && dy==0 && dx==0){
                            for(int i=0; i<stateObjects.size();i++){
                                if(stateObjects[i]->getObjectType() ==std::string("obstacles")){
                                    if((pUser->getImgYPos()+50) == stateObjects[i]->getImgYPos() && pUser->getImgXPos() == stateObjects[i]->getImgXPos())
                                        return;
                                    }
                                }
                            delta = 10; dy= 10;
                    }                    
                    playerUserCurrentRow = 1;
                    break;

                    case SDLK_RIGHT:
                        if((pUser->getImgXPos()+50) <= 640 && dx==0 && dy==0){
                            for(int i=0; i<stateObjects.size();i++){
                                if(stateObjects[i]->getObjectType() ==std::string("obstacles")){
                                    if((pUser->getImgXPos()+50) == stateObjects[i]->getImgXPos() && pUser->getImgYPos() == stateObjects[i]->getImgYPos())
                                        return;
                                    }
                                }   
                            delta = 10; dx= 10;
                        }
                        pUser->setFlipDirection(SDL_FLIP_NONE);
                    break;
                    case SDLK_LEFT:
                        if((pUser->getImgXPos()-50) >= 0 && dx==0 && dy==0){
                            for(int i=0; i<stateObjects.size();i++){
                                if(stateObjects[i]->getObjectType() ==std::string("obstacles")){
                                    if((pUser->getImgXPos()-50) == stateObjects[i]->getImgXPos() && pUser->getImgYPos() == stateObjects[i]->getImgYPos())
                                        return;
                                    }
                                }
                            delta = -10; dx = -10;
                        }
                        pUser->setFlipDirection(SDL_FLIP_HORIZONTAL);
                    break;
                }          
    }
}

bool GameScene::onEnterState(){
    srand(time(0));
    dx = dy = delta = timeStartGameTimer = 0;
    pUser = new PlayerUser();
    SmileSoundHandler::Instance()->loadSound("assets/music/backMusic.mp3", "back", SOUND_MUSIC);
    SmileSoundHandler::Instance()->playBackMusic("back", -1);
    GameScene::parseXMLLevel();
    GameSceneText = new TextObject(20, {255,0,255}, "Time left : 00");
    GameSceneText->loadObject("assets/fonts/Deutsch.ttf", "gameScene", 20, 30, 200, 120, -1, -1);
    return true;
}
bool GameScene::onExitState(){
    clearObjectsFromScene();
    return true;
}

void GameScene::clearObjectsFromScene(){
    for (std::vector<GlobalGameObjectBlueprint*>::iterator it = stateObjects.begin() ; it != stateObjects.end(); ++it)
    {
        delete (*it);
    } 
    stateObjects.clear(); 
    gameImgManager::Instance()->clearMapTextureObjects(); 
    SmileSoundHandler::Instance()->clearMapSoundRessources();
}

