##EPITECH

SRC	=	src/particle/particle.c	\
		src/game.c

OBJ = $(SRC:.c=.o)

MAIN_SRC    =    src/main.c                \

MAIN_OBJ    =    $(MAIN_SRC:.c=.o)        \

NAME    =    particle_engine

LDLIB    =    -lmyll
LIBMY    = 	   libmyll.a

CPPFLAGS    +=    -I./include/
CPFLAGS +=
LDFLAGS        += -L. -lcsfml-graphics -lcsfml-system -lcsfml-window \
-lcsfml-audio -lm

all:    $(NAME)

$(NAME):   $(OBJ) $(MAIN_OBJ)
	gcc -o $(NAME) $(OBJ) $(MAIN_OBJ) $(LIB) $(LDLIB) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(MAIN_OBJ)
	rm -f $(TEST_OBJ)

fclean: clean
	rm -f tests_run
	rm -f $(TEST_OBJ)
	rm -f $(NAME)
	rm -f *.gc*

re:	fclean all

.PHONY:	all clean fclean re
