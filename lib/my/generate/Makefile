##
## EPITECH PROJECT, 2017
## print
## File description:
## printf
##

SRC	=	oct_unprintable.c		\
		from_int_to.c			\
		from_uint_to.c			\
		my_putnbr_base.c		\
		my_put_nbr.c			\
		my_print_put_nbr.c		\
		my_print_putstr.c		\
		my_print_putchar.c		\
		my_printf.c		

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	= -Werror -g

EXE	=	my_printf

all:	$(NAME) fclean

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../libmy.a

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
