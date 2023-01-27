/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_dec_lwr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:58:27 by ydegerli          #+#    #+#             */
/*   Updated: 2022/11/11 14:05:28 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_dec_lwr(unsigned int c)
{
	int	i;

	i = 0;
	if (c > 16 || c == 16)
		i += hexa_dec_lwr(c / 16);
	if (c % 16 < 10)
		i += ft_putchar(('0' + (c % 16)));
	if ((c % 16) > 9 && (c % 16) < 16)
		i += ft_putchar('a' + ((c % 16) - 10));
	return (i);
}
