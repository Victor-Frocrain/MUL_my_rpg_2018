##
## EPITECH PROJECT, 2019
## my Makefile
## File description:
## my Makefile
##

SRC	=	my_getnbr.c			\
		my_isneg.c			\
		my_is_prime.c			\
		my_memset.c			\
		my_power.c			\
		my_putchar.c			\
		my_puterror.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_realloc.c			\
		my_revstr.c			\
		my_square_root.c		\
		my_strcapitalize.c		\
		my_strcat.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_strdup.c			\
		my_str_isalpha.c		\
		my_str_islower.c		\
		my_str_isnum.c			\
		my_str_isprintable.c		\
		my_str_isupper.c		\
		my_strlen.c			\
		my_strlowcase.c			\
		my_strncat.c			\
		my_strncmp.c			\
		my_strncpy.c			\
		my_str_to_word.c		\
		my_strupcase.c			\
		redirect_all_std.c		\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-I ../../include/

NAME	=	libmy.a

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f ../$(NAME)

re:		fclean all
