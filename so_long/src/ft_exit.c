/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:19:00 by ydegerli          #+#    #+#             */
/*   Updated: 2023/01/21 17:19:45 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->line_count)
	{
		free(arg->map[i]);
		i++;
	}
	free(arg->map);
	free(arg);
}

int	ft_exit(t_arg *arg)
{
	mlx_clear_window(arg->mlx, arg->mlx_win);
	mlx_destroy_image(arg->mlx, arg->back);
	mlx_destroy_image(arg->mlx, arg->wall);
	mlx_destroy_image(arg->mlx, arg->player);
	mlx_destroy_image(arg->mlx, arg->colec);
	mlx_destroy_image(arg->mlx, arg->enemy);
	ft_free_map(arg);
	exit(0);
	return (0);
}
