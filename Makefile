DEBUG_ENABLED=yes
CC=g++
ifeq ($(DEBUG_ENABLED),yes)
	CFLAGS=-W -Wall -g
else
	CFLAGS=-W -Wall
endif
LDFLAGS=`sdl2-config --cflags --libs` -lSDL2_mixer -lSDL2_ttf -ltinyxml2 -std=c++11

EXEC=openquest
SRC= $(wildcard *.cpp image_manager/*.cpp game_objects/*.cpp state_machines/*.cpp soundHandler/*.cpp font_manager/*.cpp)
OBJ= $(SRC:.c=.o)

all: $(EXEC)
ifeq ($(DEBUG_ENABLED),yes)
	@echo "Game generated in debug mode"
else
	@echo "Game generated in release mode"
endif
	@echo "run game as follow : $$ ./openquest"
openquest: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)


%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean distclean

clean:
	@rm -rf *.o

distclean: clean
	@rm -rf $(EXEC)

