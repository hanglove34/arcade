##
## EPITECH PROJECT, 2019
## CPool_d01
## File description:
## exo00
##

SRC		=		main.cpp					\
				src/Arcade.cpp				\
				src/my.cpp					\
				src/Loader.cpp

OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++14 -I ./include -ldl

CC		=	g++

NAME	=	arcade

all:		core lib game

core:		$(NAME)

games: game

game: clean
	make -C ./games/qix/
	make clean
	make -C ./games/nibbler/

lib: clean
	rm -f ./src/Arcade.o
	make -C ./lib/allegro
	make clean
	make -C ./lib/sfml
	make clean
	make -C ./lib/ncurses

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)  $(CXXFLAGS)

clean:
		rm -f $(OBJ)
		make clean -C ./lib/sfml
		make clean -C ./lib/allegro
		make clean -C ./lib/ncurses
		make clean -C ./games/qix
		make clean -C ./games/nibbler

fclean: 	clean
		rm -f $(NAME)
		make fclean -C ./lib/sfml
		make fclean -C ./lib/allegro
		make fclean -C ./lib/ncurses
		make fclean -C ./games/qix
		make fclean -C ./games/nibbler

re:	clean all
