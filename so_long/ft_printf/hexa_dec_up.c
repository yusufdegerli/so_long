/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_dec_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:59:24 by ydegerli          #+#    #+#             */
/*   Updated: 2022/11/11 14:05:48 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_dec_up(unsigned int c)
{
	int	i;

	i = 0;
	if (c > 15)
	i += hexa_dec_up(c / 16);
	if (c % 16 < 10)
	i += ft_putchar(('0' + (c % 16)));
	if ((c % 16) > 9 && (c % 16) < 16)
	i += ft_putchar('A' + ((c % 16) - 10));
	return (i);
}
