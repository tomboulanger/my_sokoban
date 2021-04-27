##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC	=	src/my_popup.c \
		src/tab.c \
		src/move.c \
		src/move_utils.c \
		src/victory.c \
		src/main.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -g3

LDFLAGS	=	-lmy -L ./lib/my/ -lncurses

NAME	=	my_sokoban

CC		=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	rm src/*.o

clean:
	make -C lib/my/ clean
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	make -C lib/my/ fclean
	rm -f $(NAME)

re: fclean all