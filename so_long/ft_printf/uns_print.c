/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:09:34 by ydegerli          #+#    #+#             */
/*   Updated: 2022/11/11 14:10:06 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	uns_print(unsigned int num)
{
	int	counter;

	counter = 0;
	if (num > 9)
		counter += uns_print(num / 10);
	counter += ft_putchar(num % 10 + '0');
	return (counter);
}
