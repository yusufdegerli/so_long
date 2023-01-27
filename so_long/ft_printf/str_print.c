/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:04:03 by ydegerli          #+#    #+#             */
/*   Updated: 2022/11/11 14:16:07 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	str_print(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		str_print("(null)");
		return (6);
	}
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}
