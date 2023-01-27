# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 10:19:25 by ydegerli          #+#    #+#              #
#    Updated: 2023/01/23 10:29:37 by ydegerli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

SRCS = src/so_long.c src/ft_map_init.c src/ft_put.c src/map_read.c \
		src/ft_exit.c src/ft_action.c src/check1.c src/utils.c \
		src/ft_calloc.c src/check2.c src/ft_sprite.c \
		src/ft_putchar_fd.c src/ft_putendl_fd.c src/ft_putstr_fd.c 

OBJS = $(SRCS:.c=.o)

GNL  = $(wildcard gnl/*.c)
FT_PRINTF = $(wildcard ft_printf/*.c)
GNLOBJS = $(GNL:.c=.o)
FT_PRINTFOBJS = $(FT_PRINTF:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS) $(GNLOBJS) $(FT_PRINTFOBJS)
	Make -C mlx
	$(CC) $(OBJS) $(GNLOBJS) $(FT_PRINTFOBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(GNLOBJS) $(FT_PRINTFOBJS)

re: fclean all