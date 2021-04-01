##
## EPITECH PROJECT, 2017
## Bootstrap_my_printf
## File description:
## Makefile
##

SRC		=	lib_arcade_allegro.cpp		\
			../../src/Arcade.cpp		\

CXXFLAGS	=	-shared -fPIC -lallegro -lallegro_font -lallegro_ttf -lallegro_primitives -I/usr/include/allegro5 -L/usr/lib -I ../.././include -std=c++11

OBJS	=	$(SRC:.cpp=.o)

NAME	=	lib_arcade_allegro.so

all:	$(NAME)

$(NAME):	$(OBJS)
	g++ $(OBJS) $(CXXFLAGS) -o $(NAME)
	cp $(NAME) ..
	cp $(NAME) ../../

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../$(NAME)

re:	clean all
