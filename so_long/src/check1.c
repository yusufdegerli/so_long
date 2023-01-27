/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:01:38 by ydegerli          #+#    #+#             */
/*   Updated: 2023/01/21 17:05:41 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ber_check(char *map_name)
//Haritanın uzantısının ".ber" olduğunu kontrol ettim.
//I checked that the extension of the map is ".ber".
{
	int		len;
	char	*tmp;

	tmp = ft_strdup(ft_strrchr(map_name, '/'));
	len = ft_strlen(tmp);
	if (len > 4)
	{
		if (tmp[len - 1] != 'r' || tmp[len - 2] != 'e'
			|| tmp[len - 3] != 'b' || tmp[len - 4] != '.'
			|| len <= 9)
		{
			ft_printf("Hata! Harita .ber uzantılı olmalı!\n");
			free(tmp);
			exit(1);
		}
		free(tmp);
	}
	else
	{
		ft_printf("Hata! Harita .ber uzantılı olmalı!\n");
		free(tmp);
		exit(1);
	}
}

void	ft_map_check(t_arg *arg)
//Harita kontrolü.
//Map check.
{
	static int	i;
	static int	j;

	i = 0;
	j = 0;
	while (i < arg->line_count)
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] == 'C')
				arg->coin_count++;
			else if (arg->map[i][j] == 'E')
				arg->exit_count++;
			else if (arg->map[i][j] == 'P')
			{
				arg->player_count++;
				arg->player_x = j;
				arg->player_y = i;
			}
			j++;
		}
		i++;
	}
	ft_fe_count_check(arg);
}

void	ft_rectangular_ctl(t_arg *arg)
//Haritamın kenar uzunlukları, paralel kenarlara eşit uzunlukta mı kontrol ediyorum.
//I'm checking if the side lengths of my map are equal to the parallel sides.
{
	size_t	line_len1;
	size_t	line_len2;
	int		i;
	int		j;

	i = 0;
	while (i < arg->line_count)
	{
		j = 0;
		while (j < arg->line_count)
		{
			line_len1 = ft_strlen(arg->map[i]);
			line_len2 = ft_strlen(arg->map[j]);
			if (line_len2 != line_len1)
			{
				ft_printf("Error! The map is not rectangular.\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_surrounded_wall_check(t_arg *arg)
//Haritamın etrafı, duvarlarla çevrili olduğunu kontrol ediyorum.
//I'm checking that my map is surrounded by walls.
{
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	while (arg->map[i])
	{
		len++;
		i++;
	}
	i = 0;
	while (i < (ft_strlen(arg->map[0]) - 1))
	{
		if (arg->map[0][i] != '1' || arg->map[len - 1][i] != '1')
		{
			ft_printf("Duvar Hatası!\nWall Error!");
			exit(1);
		}
		i++;
	}
	ft_leftright_wall_check(arg);
}

void	ft_leftright_wall_check(t_arg *arg)
{
//Haritamın sağ ve sol duvarlarını kontrol ediyorum.
//I check the right and left walls of my map.
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(arg->map[0]) - 1;
	while (i < arg->line_count)
	{
		if (arg->map[i][0] != '1' || arg->map[i][len - 1] != '1')
		{
			ft_printf("Duvar Hatası!\nWall Error!");
			exit(1);
		}
		i++;
	}
	arg->tmp_coin_count = arg->coin_count;
}
