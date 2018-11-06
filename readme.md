# Opensource quest

Follow the opensource community and gather as much as you can of opensource blocks, pay attention to proprietary enemies blocks (*which do not play a fair play*).

Enjoy the game!!!!!!


# Prerequest

Opensource quest is based on **SDL** and some of it's extensions :

    $ sudo apt-get install libsdl2-dev
    $ sudo apt-get install libsdl2-mixer-2.0-0
    $ sudo apt-get install libsdl2-ttf-dev

## Compilation

A makefile will be available soon but one can :

$ g++ main.cpp GameLogic.cpp image_manager/ImgManager.cpp game_objects/PlayerUser.cpp state_machines/EntryMenu.cpp state_machines/StateMachineDriver.cpp game_objects/MenuObject.cpp HandleUserEvent.cpp soundHandler/SoundHandler.cpp game_objects/TextObject.cpp font_manager/FontManager.cpp state_machines/GameScene.cpp state_machines/GameOverScene.cpp -o main \`sdl2-config --cflags --libs\` -lSDL2_mixer -lSDL2_ttf


**Have faith in opensource!!!!!!!!!!!!** 
