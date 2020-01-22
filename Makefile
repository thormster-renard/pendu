#CFLAGS= -W -Wall -ansi -pedantic -Wextra -Werror -std=gnu99
CFLAGS=	-g3 -std=gnu99

NAME=	pendu

SRC=	$(wildcard *.c)

OBJ=	$(SRC:.c=.o)

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	clean fclean all
