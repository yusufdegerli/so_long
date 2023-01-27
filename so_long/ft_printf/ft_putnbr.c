/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:10:37 by ydegerli          #+#    #+#             */
/*   Updated: 2022/11/11 14:10:56 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_putnbr(int n)
{
	static int	counter;

	counter = 1;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar('-');
		}
		if (n > 9)
		{
			ft_putnbr(n / 10);
			counter++;
		}
		ft_putchar(n % 10 + '0');
	}
	return (counter);
}
