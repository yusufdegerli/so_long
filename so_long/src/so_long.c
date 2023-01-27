/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:52:29 by ydegerli          #+#    #+#             */
/*   Updated: 2023/01/21 18:54:17 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_param(t_arg *arg)
{
	arg->valid_e = 0;
	arg->tmp_coin_count = 0;
	arg->move = 0;
	arg->fail = 0;
	arg->success = 0;
	arg->coin_count = 0;
	arg->exit_count = 0;
	arg->player_count = 0;
	arg->exit_count = 0;
	arg->player_x = 0;
	arg->player_y = 0;
	arg->past_x = 0;
	arg->past_y = 0;
	arg->line_count = 0;
	arg->enemy = NULL;
	arg->left_animation = NULL;
	arg->right_animation = NULL;
	arg->up_animation = NULL;
	arg->down_animation = NULL;
}

void	init_param2(t_arg *arg)
{
	arg->mat = NULL;
	arg->map = NULL;
	arg->tmp_map = NULL;
	arg->mlx = NULL;
	arg->win = NULL;
	arg->mlx_win = NULL;
	arg->wall = NULL;
	arg->player = NULL;
	arg->img_exit = NULL;
	arg->colec = NULL;
	arg->back = NULL;
}

int	main(int ac, char **av)
{
	if (!av)
		return (0);
	if (ac != 2)
	{
		ft_printf("Hata! Hatalı argüman kullanımı!\n \
		Error! Wrong using arg.");
		return (1);
	}
	ft_ber_check(av[1]);
	ft_map_init(av[1]);
	return (0);
}
