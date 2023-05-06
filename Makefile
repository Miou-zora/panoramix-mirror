##
## EPITECH PROJECT, 2023
## panoramix-mirror [WSL : Ubuntu]
## File description:
## Makefile
##

SRC_DIR		=	src
SRC			=	help.c							\
				panoramix.c						\
				init_core.c						\
				villager.c						\
				druid.c							\

SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC))

MAIN		=	main.c

MAIN_OBJ	=	$(MAIN:%.c=%.o)

OBJ			=	$(SRC:%.c=%.o)

NAME		=	panoramix

CFLAGS		=	-Wall -Wextra -Werror -I./include

CC			=	gcc

all:	$(NAME)

$(NAME):	$(OBJ) $(MAIN_OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MAIN_OBJ) $(CFLAGS)

debug: CFLAGS += -g
debug: re

tests_run:

clean:
	rm -f $(MAIN_OBJ)
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
