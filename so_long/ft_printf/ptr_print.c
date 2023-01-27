/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:01:38 by ydegerli          #+#    #+#             */
/*   Updated: 2022/11/11 14:15:03 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	hexa_dec_lwr_ptr(unsigned long c)
{
	int	i;

	i = 0;
	if (c > 15)
		i += hexa_dec_lwr_ptr(c / 16);
	if ((c % 16) < 10)
		i += ft_putchar(('0' + (c % 16)));
	if ((c % 16) > 9 && (c % 16) < 16)
		i += ft_putchar('a' + ((c % 16) - 10));
	return (i);
}

int	ptr_print(unsigned long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		hexa_dec_lwr_ptr(ptr);
		print_length += ptr_len(ptr);
	}
	return (print_length);
}
