##
## EPITECH PROJECT, 2018
## Arcade
## File description:
## Makefile Ncurses
##

SRC	=	NCurses.cpp				\
		../../src/Arcade.cpp		\

CXXFLAGS	=	-shared -fPIC -lncurses -I ../.././include -std=c++14

OBJS	=	$(SRC:.cpp=.o)

NAME	=	lib_arcade_ncurses.so

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
