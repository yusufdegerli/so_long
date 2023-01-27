/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:20:10 by ydegerli          #+#    #+#             */
/*   Updated: 2023/01/21 18:36:13 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_create_xpm(t_arg *arg)
{
//Haritada yazılan karakterlere göre istenilen görselleri koyuyorum.
//I put the desired images according to the characters written on the map.
	int	x;
	int	y;

	arg->back = mlx_xpm_file_to_image(arg->mlx,
			"./images/background.xpm", &x, &y);
	arg->colec = mlx_xpm_file_to_image(arg->mlx,
			"./images/coin.xpm", &x, &y);
	arg->img_exit = mlx_xpm_file_to_image(arg->mlx,
			"./images/door.xpm", &x, &y);
	arg->player = mlx_xpm_file_to_image(arg->mlx,
			"./images/character.xpm", &x, &y);
	arg->wall = mlx_xpm_file_to_image(arg->mlx,
			"./images/wall.xpm", &x, &y);
	arg->enemy = mlx_xpm_file_to_image(arg->mlx,
			"./images/venom.xpm", &x, &y);
	ft_create_xpm2(arg);
	if (!arg->back || !arg->colec || !arg->wall || !arg->player)
		return (1);
	return (0);
}

void	ft_create_xpm2(t_arg *arg)
{
//Karakterimin hareket etmesine bağlı olarak, kullanılması gereken görselleri koyuyorum.
//Depending on the movement of my character, I put the images that should be used.
	int	x;
	int	y;

	arg->left_animation = mlx_xpm_file_to_image(arg->mlx,
			"./images/character_left.xpm", &x, &y);
	arg->right_animation = mlx_xpm_file_to_image(arg->mlx,
			"./images/character_right.xpm", &x, &y);
	arg->up_animation = mlx_xpm_file_to_image(arg->mlx,
			"./images/character_top.xpm", &x, &y);
	arg->down_animation = mlx_xpm_file_to_image(arg->mlx,
			"./images/character_down.xpm", &x, &y);
}

void	ft_put_win(t_arg *arg)
{
//Haritada olan karakterli işleyip, istenilene göre görsel koyuyorum.
//I process the characters on the map and put visuals according to the request.
	int	x;
	int	y;

	x = -1;
	y = 0;
	while (arg->map[y][++x])
	{
		if (y != arg->line_count - 1 && arg->map[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		if (arg->map[y][x] == 'P')
			ft_sprite(arg, x, y);
		if (arg->map[y][x] == 'E')
			ft_put(arg, arg->img_exit, x, y);
		if (arg->map[y][x] == '1')
			ft_put(arg, arg->wall, x, y);
		if (arg->map[y][x] == 'C')
			ft_put(arg, arg->colec, x, y);
		if (arg->map[y][x] == '0')
			ft_put(arg, arg->back, x, y);
		if (arg->map[y][x] == 'V')
			ft_put(arg, arg->enemy, x, y);
	}
}

void	ft_map_init(char *str)
{
//Fonkyion kontrolü.
//Function check.
	t_arg	*arg;
	char	*str_move;

	arg = malloc(sizeof(t_arg));
	init_param(arg);
	init_param2(arg);
	ft_read_map(arg, str);
	arg->mlx = mlx_init();
	arg->mlx_win = mlx_new_window(arg->mlx, 64 * (ft_strlen(arg->map[0]) - 1),
			64 * arg->line_count, "SO_LONG");
	if (!arg->mlx || !arg->mlx_win || ft_create_xpm(arg))
		ft_printf("mlx failed!!!\n");
	str_move = ft_itoa(arg->move);
	mlx_string_put(arg->mlx, arg->mlx_win, 15, 15, 16777215, str_move);
	free(str_move);
	ft_map_init2(arg);
}

int	ft_map_init2(t_arg *arg)
{
//Fonksiyon kontrolü.
//Function check.
	ft_put_win(arg);
	ft_map_check(arg);
	ft_rectangular_ctl(arg);
	ft_surrounded_wall_check(arg);
	ft_validmap_check(arg, arg->player_x, arg->player_y);
	ft_path_check(arg);
	mlx_hook(arg->mlx_win, 17, 1L << 2, ft_exit, arg);
	mlx_hook(arg->mlx_win, 2, 1L << 2, ft_action, arg);
	mlx_loop(arg->mlx);
	return (0);
}
