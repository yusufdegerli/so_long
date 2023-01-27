/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:10:58 by ydegerli          #+#    #+#             */
/*   Updated: 2023/01/21 17:10:59 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_add(t_arg *arg, int x, int y)
{
	arg->player_x = x;
	arg->player_y = y;
	arg->player_count++;
}

void	ft_numb_of_elem_check(t_arg *arg)
{
	int	x;
	int	y;

	arg->player_count = 0;
	arg->exit_count = 0;
	arg->coin_count = 0;
	y = 0;
	while (arg->map[y])
	{
		x = 0;
		while (arg->map[y][x])
		{
			if (arg->map[y][x] == 'P')
				ft_add(arg, x, y);
			if (arg->map[y][x] == 'E')
				arg->exit_count++;
			if (arg->map[y][x] == 'C')
				arg->coin_count++;
			x++;
		}
		y++;
	}
}

void	ft_map_mani(t_arg *arg, int x, int y)
//Haritamda olması gereken objeleri kontrol ediyor ve kullanışlılarını yazıyorum.
//I check the objects that should be on my map and write the useful ones.
{
	if (arg->map[y][x] != '1' && arg->map[y][x] != 'E' && arg->map[y][x] != 'V')
	{
		arg->map[arg->player_y][arg->player_x] = '0';
		if (arg->map[y][x] == 'C')
			arg->coin_count--;
		arg->move++;
		ft_putnbr(arg->move);
		write(1, "\n", 1);
		arg->map[y][x] = 'P';
		arg->player_x = x;
		arg->player_y = y;
	}
	else if (!arg->coin_count && arg->map[y][x] == 'E')
		ft_exit(arg);
	else if (arg->map[y][x] == 'V')
	{
		ft_printf("YOU DIED!\n");
		ft_exit(arg);
	}
}

int	ft_action(int key, t_arg *arg)
//Karakterimin basılan tuşlara göre, koordinat sistemine göre hareket etmesini yapıyorum.
//I make my character move according to the coordinate system, according to the keys pressed.
{
	int	x;
	int	y;

	x = arg->player_x;
	y = arg->player_y;
	arg->past_x = arg->player_x;
	arg->past_y = arg->player_y;
	if (key == W)
		y--;
	else if (key == S)
		y++;
	else if (key == D)
		x++;
	else if (key == A)
		x--;
	else if (key == ESC)
		ft_exit(arg);
	else
		return (0);
	ft_map_mani(arg, x, y);
	ft_action2(arg);
	return (0);
}

void	ft_action2(t_arg *arg)
{
//Kontrol ve hareket sayacı.
//Control and movement counter.
	char	*str_move;

	ft_numb_of_elem_check(arg);
	mlx_clear_window(arg->mlx, arg->mlx_win);
	ft_put_win(arg);
	str_move = ft_itoa(arg->move);
	mlx_string_put(arg->mlx, arg->mlx_win, 15, 15, 16777215, str_move);
	free(str_move);
}
