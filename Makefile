##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME 	= panoramix

SRC 	= 	panoramix.c \
		  	src/helper.c \
			src/args_gestion.c \
			src/villager.c \
			src/druid.c \
			src/init_struct.c \

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -g3 -I./include -lpthread

all		: $(NAME)

$(NAME)	: $(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean 	:
		rm -rf $(OBJ)
		rm -rf vgcore.*

fclean 	: clean
		rm -rf $(NAME)

re		: fclean all