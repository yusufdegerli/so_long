/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:00:25 by ydegerli          #+#    #+#             */
/*   Updated: 2022/11/11 14:12:41 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_print(int s)
{
	long	tmp;
	int		i;

	i = 0;
	tmp = (long)s;
	if (tmp == -2147483648)
		i += ft_putstr("-2147483648");
	else
	{
		if (tmp < 0)
		{
			tmp *= -1;
			i += ft_putchar('-');
		}
		if (tmp > 9)
			i += ft_putnbr(tmp / 10);
		i += ft_putchar(tmp % 10 + '0');
	}
	return (i);
}
