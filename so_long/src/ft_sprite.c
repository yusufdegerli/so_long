/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:44:20 by ydegerli          #+#    #+#             */
/*   Updated: 2023/01/21 18:44:53 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sprite(t_arg *arg, int x, int y)
{
	ft_put(arg, arg->down_animation, x, y);
	if (arg->past_x > arg->player_x)
		ft_put(arg, arg->left_animation, x, y);
	if (arg->past_x < arg->player_x)
		ft_put(arg, arg->right_animation, x, y);
	if (arg->past_y < arg->player_y)
		ft_put(arg, arg->down_animation, x, y);
	if (arg->past_y > arg->player_y)
		ft_put(arg, arg->up_animation, x, y);
}
//karakterin koordinat sistemine göre, azalıp artmasına bağlı olarak animasyon ekledim.
//According to the coordinate system of my character, I added animation depending on decreasing and running.