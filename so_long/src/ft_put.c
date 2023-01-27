/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:37:10 by ydegerli          #+#    #+#             */
/*   Updated: 2023/01/21 18:37:21 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put(t_arg *arg, void *img, int x, int y)
{
	mlx_put_image_to_window(arg->mlx, arg->mlx_win, img, 64 * x, 64 * y);
}
