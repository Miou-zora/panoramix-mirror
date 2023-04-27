##
## EPITECH PROJECT, 2023
## panoramix-mirror [WSL : Ubuntu]
## File description:
## Makefile
##

SRC			=

MAIN		=	main.c

OBJ			=	$(SRC:%.c=%.o)

NAME		=	panoramix

CFLAGS		=	-Wall -Wextra -Werror -I./include

CC			=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MAIN) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all


