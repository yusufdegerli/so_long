/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:35:18 by ydegerli          #+#    #+#             */
/*   Updated: 2022/12/25 17:35:21 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ctl(va_list lst, char c)
{
	int	i;

	i = 0;
	if (c == 'd' || c == 'i')
		i += int_print(va_arg(lst, int));
	else if (c == 's')
		i += str_print(va_arg(lst, char *));
	else if (c == 'c')
		i += ft_putchar(va_arg(lst, int));
	else if (c == 'p')
		i += ptr_print(va_arg(lst, unsigned long));
	else if (c == 'u')
		i += uns_print(va_arg(lst, unsigned int));
	else if (c == 'x')
		i += hexa_dec_lwr(va_arg(lst, unsigned long));
	else if (c == 'X')
		i += hexa_dec_up(va_arg(lst, unsigned long));
	else if (c == '%')
		i += write(1, "%", 1);
	return (i);
}

int	ft_printf(const char *start, ...)
{
	size_t	i;
	size_t	j;
	int		counter;
	va_list	ag;

	counter = 0;
	j = 0;
	i = 0;
	va_start (ag, start);
	while (start[j])
	{
		if (start[j] == '%')
		{
			counter += ctl(ag, start[j + 1]);
			j++;
		}
		else
		counter += write(1, &start[j], 1);
	j++;
	}
	return (counter);
}
