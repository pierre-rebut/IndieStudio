##
## Makefile for Make in /home/rebut_p/Programmation/CPP/cpp_indie_studio/tmp/ogre
## 
## Made by Pierre Rebut
## Login   <rebut_p@epitech.net>
## 
## Started on  Tue May 10 11:47:34 2016 Pierre Rebut
## Last update Sun Jun  5 22:45:27 2016 Pierre Rebut
##

EXEC	=	Gauntlet
SHELL	=	/bin/bash

NAME	=	Gauntlet_app

SRC	=	$(shell cat sources.mk)

OBJ	=	$(SRC:.cpp=.o)

CXX	=	g++

CXXFLAGS+=	-Wall -lpthread -I include -I include/elems -I include/elems/perso \
		-I include/cegui -I SHARE/shared_inc -I SHARE/static_inc -std=c++11

CXXLIB	+=	-L./SHARE/shared_lib -L./SHARE/static_lib -lOgreMain -lOIS \
		-lfmodL -llua -ldl -lboost_system -lCEGUIBase-0 -lCEGUIExpatParser \
		-lCEGUIOgreRenderer-0

all	:	$(NAME) $(EXEC)

$(NAME)	:	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(CXXLIB)

install	:	deps
		rm -rf ~/Gauntlet &&
		mkdir ~/Gauntlet &&
		cp -R SHARED ~/Gauntlet/ &&
		cp -R config ~/Gauntlet/ &&
		cp Gauntlet_app &&
		cd ~/Gauntlet &&
		@echo "#!/bin/sh" > $(EXEC)
		@echo -n "cd " >> $(EXEC)
		@pwd >> $(EXEC)
		@echo "export LD_LIBRARY_PATH=./SHARE/shared_lib:./SHARE/static_lib" >> $(EXEC)
		@echo "./"$(NAME) >> $(EXEC)
		@chmod +x $(EXEC)

deps:
		cd SHARE && ./build.sh && cd ..;
		make all;

$(EXEC)	:
		@echo "#!/bin/sh" > $(EXEC)
		@echo -n "cd " >> $(EXEC)
		@pwd >> $(EXEC)
		@echo "export LD_LIBRARY_PATH=./SHARE/shared_lib:./SHARE/static_lib" >> $(EXEC)
		@echo "./"$(NAME) >> $(EXEC)
		@chmod +x $(EXEC)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME) $(EXEC)

re	:	fclean
		$(MAKE) all
