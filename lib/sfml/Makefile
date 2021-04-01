##
## EPITECH PROJECT, 2017
## Bootstrap_my_printf
## File description:
## Makefile
##

SRC		=	lib_arcade_sfml.cpp		\
			../../src/Arcade.cpp		\

CXXFLAGS	=	-shared -fPIC -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -I ../.././include -std=c++11

OBJS	=	$(SRC:.cpp=.o)

NAME	=	lib_arcade_sfml.so

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
