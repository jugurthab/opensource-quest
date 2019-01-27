#include "GameScene.h"

const std::string GameScene::gameStateID = "GAME_STATE";


void GameScene::updateState(){
    
    for(int i=0; i<stateObjects.size();i++)
        stateObjects[i]->updateObject();

    
        
}
void GameScene::renderState(){
    
    for(int i=0; i<stateObjects.size();i++)
        stateObjects[i]->drawObject(SDL_FLIP_NONE);

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

    // Get reference to root element "geeks"
    tinyxml2::XMLNode* pRoot = xmlDoc.RootElement();
    // Check if pRoot is non empty
    if (pRoot == NULL){
        std::cout << "Invalid XML file" << std::endl;
        return false;
    }   
    // Display root node    
    std::cout << "Root Element : " << pRoot->Value() << std::endl;
    


    // Traverse root element to get it's children    (geek tags in our example) 
    for(tinyxml2::XMLElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {      
        std::cout << "TAG : " << e->Value() << std::endl;
        if(e->Value() == std::string("level_difficulty")){
            std::cout << "level_difficulty : " << e->GetText() << std::endl;
        }
        else if(e->Value() == std::string("player")){ 
            int posX = 0, posY = 0;
            std::string pathToImg = "assets/";
            
            std::cout << e->Attribute("id") << std::endl;
            pathToImg += e->Attribute("id");
            for(tinyxml2::XMLElement* subEl = e->FirstChildElement(); subEl != NULL; subEl = subEl->NextSiblingElement()){
                
                if(subEl->Value() == std::string("positionX"))
                    posX = atoi(subEl->GetText());
                else
                    posY = atoi(subEl->GetText());
                std::cout << subEl->Value() << " : " << subEl->GetText() << std::endl;
            }
            pUser->loadObject(pathToImg, "rider", posX, posY, 50, 50, 0, 0);
            stateObjects.push_back(pUser);
        }

        else if(e->Value() == std::string("enemies")) {
            int posX = 0, posY = 0;
            std::string pathToImg = "assets/";
            

            std::cout << e->Attribute("id") << std::endl;
            pathToImg += e->Attribute("id");
            for(tinyxml2::XMLElement* subEl = e->FirstChildElement(); subEl != NULL; subEl = subEl->NextSiblingElement()){
                Enemy* enemy = new Enemy();
                std::cout << subEl->Value() << " : " << subEl->Attribute("x") << subEl->Attribute("y") << std::endl;

                
                
                posX = atoi(subEl->Attribute("x"));
                posY = atoi(subEl->Attribute("y"));
                std::cout << subEl->Value() << " : " << subEl->GetText() << std::endl;
                enemy->loadObject(pathToImg, e->Attribute("id"), posX, posY, 50, 50, 0, 0);
                stateObjects.push_back(enemy); 
            }         
  
        }
    
        else if(e->Value() == std::string("obstacles")){
            int posX = 0, posY = 0;
            std::string pathToImg = "assets/";
            pathToImg += e->Attribute("id");
            std::cout << e->Attribute("id") << std::endl;
            for(tinyxml2::XMLElement* subEl = e->FirstChildElement(); subEl != NULL; subEl = subEl->NextSiblingElement()){
                Block* block = new Block();
                std::cout << subEl->Value() << " : " << subEl->Attribute("x") << subEl->Attribute("y") << std::endl;
                posX = atoi(subEl->Attribute("x"));
                posY = atoi(subEl->Attribute("y"));
                std::cout << subEl->Value() << " : " << subEl->GetText() << std::endl;
                block->loadObject(pathToImg, "block", posX, posY, 50, 50, 0, 0);
                stateObjects.push_back(block);
            }  
        }
        std::cout << "------------------------------------" << std::endl;    
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
                        if((pUser->getImgYPos()-50) >= 0) 
                            pUser->setImgYPos(pUser->getImgYPos()-50);
                    break;
            
                    case SDLK_DOWN:
                        if((pUser->getImgYPos()+50) <= 480)
                            pUser->setImgYPos(pUser->getImgYPos()+50);
                    break;

                    case SDLK_RIGHT:
                        if((pUser->getImgXPos()+50) <= 640)
                            pUser->setImgXPos(pUser->getImgXPos()+50);
                    break;
                    case SDLK_LEFT:
                        if((pUser->getImgXPos()-50) >= 0)
                            pUser->setImgXPos(pUser->getImgXPos()-50);
                    break;
                }
                
                
            
    }
}

bool GameScene::onEnterState(){
    pUser = new PlayerUser();
    GameScene::parseXMLLevel();
    GameSceneText = new TextObject(40, {255,0,255}, "Game scene");
    GameSceneText->loadObject("assets/fonts/PTC55F.ttf", "gameScene", 20, 30, 200, 120, -1, -1);
    
    std::cout << "onEnter GameScene" << std::endl;
    
    SmileSoundHandler::Instance()->loadSound("assets/music/backMusic.mp3", "back", SOUND_MUSIC);
    SmileSoundHandler::Instance()->playBackMusic("back", -1);

    stateObjects.push_back(GameSceneText);        

    return true;
}
bool GameScene::onExitState(){
    std::cout << "onExit GameScene" << std::endl;
    return true;
}



