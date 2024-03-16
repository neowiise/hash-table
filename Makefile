##
## EPITECH PROJECT, 2023
## minishell
## File description:
## Makefile
##

NAME = libhashtable.a

SRC =	src/display_hash.c	\
		src/create_hash.c	\
		src/hash_function.c	\
		src/delete_hash.c	\
		src/insert_element.c	\
		src/delete_element.c	\
		src/search.c 			\
		lib/handlings.c			\
		lib/mini_printf.c		\
		lib/my_getnbr.c			\
		lib/my_put_nbr.c		\
		lib/my_putchar.c		\
		lib/my_putstr.c			\
		lib/my_strcmp.c			\
		lib/my_strncpy.c		\
		lib/my_strcpy.c			\
		lib/my_strlen.c			\

OBJ = $(SRC:.c=.o)

CFLAGS = -Wextra -Wall

all: $(OBJ)
	ar rc $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
