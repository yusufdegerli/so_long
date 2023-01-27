/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:07:04 by ydegerli          #+#    #+#             */
/*   Updated: 2023/01/21 17:07:07 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_validmap_check(t_arg *arg, int x, int y)
//Haritamdaki nesneler, ulaşılamaz bir yerde olup olmadığını kontrol ediyorum.
//I check if the objects in my map are in an unreachable place.
{
	if (arg->tmp_map[y][x] == 'E')
		arg->valid_e = 1;
	if (arg->tmp_map[y][x] != 'E' && arg->tmp_map[y][x] != '1')
	{
		if (arg->tmp_map[y][x] == 'C')
			arg->tmp_coin_count--;
		arg->tmp_map[y][x] = '.';
		if (arg->tmp_map[y][x + 1] != '1' &&
			arg->tmp_map[y][x + 1] != '.')
			ft_validmap_check(arg, x + 1, y);
		if (arg->tmp_map[y][x - 1] != '1' &&
			arg->tmp_map[y][x - 1] != '.')
			ft_validmap_check(arg, x - 1, y);
		if (arg->tmp_map[y - 1][x] != '1' &&
			arg->tmp_map[y - 1][x] != '.')
			ft_validmap_check(arg, x, y - 1);
		if (arg->tmp_map[y + 1][x] != '1' &&
			arg->tmp_map[y + 1][x] != '.')
			ft_validmap_check(arg, x, y + 1);
	}
}

void	ft_path_check(t_arg *arg)
{
//Haritamdaki nesneler, ulaşılamaz bir yerde olup olmadığını kontrol ediyorum.
//I check if the objects in my map are in an unreachable place.
	int	i;

	i = 0;
	while (arg->tmp_map[i])
	{
		free(arg->tmp_map[i]);
		i++;
	}
	free(arg->tmp_map);
	if (arg->valid_e != 1)
	{
		ft_printf("Hata! Çıkış Ulaşılmaz bir yerde!");
		exit(1);
	}
	if (arg->tmp_coin_count != 0)
	{
		ft_printf("Hata! Puan ulaşılmaz bir yerde!");
		exit(1);
	}
}
