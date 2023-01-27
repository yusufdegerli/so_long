NAME = libftprintf.a
SOURCES = \
	ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c hexa_dec_lwr.c hexa_dec_up.c int_print.c ptr_print.c str_print.c uns_print.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
